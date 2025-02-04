import socket
import re
import swissknife

LOGIN = """100#{gli&&er}{"user_name":"USER","password":"PASS","enable_push_notifications":true}##"""
CHECK_SUM = """110#{gli&&er}ASCI_CODE##"""

FORMAT = 'CODE#{gli&&er}{DATA}##'
URL = "url"

IP = "ip"
GET_RECV = 1024
PORT = 1336
sparkle_cookie = 0

ERROR_MESSAGE = {
    1:"109#",
    2:"108#",
    3:"952#",
    4:"115#",
    5:"109#",

}

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
        flag_app =True
        while flag_app:
            clientSocket.connect((IP, PORT))
            name,passward = swissknife.login_info()
            login_exm = LOGIN
            login_exm = login_exm.replace("USER", name).replace("PASS", passward)
            clientSocket.sendall(login_exm.encode())
            get_message = clientSocket.recv(GET_RECV).decode()
            login_error = re.search(rf'{ERROR_MESSAGE[1]}',get_message)
            user_login = re.search(rf'{ERROR_MESSAGE[2]}',get_message)
            illegal_user = re.search(rf'{ERROR_MESSAGE[3]}',get_message)
            if login_error or illegal_user or user_login:
                login_error = illegal_user = user_login = False
                print("there is no account for app")
                want = input("do you want to get with app(y/n):")
                if want == 'n':
                    login_error = illegal_user = user_login = True
                    work_app = False
                    flag_app = flag_app
                    break
                elif want == 'y':
                    work_app == True
                    break
                else:
                    print("eroore")
                    exit()
            else:
                exm_check_sum = CHECK_SUM.replace("ASCI_CODE", str(sum(ord(char) for char in name) + sum(ord(char) for char in passward)))
                clientSocket.sendall(exm_check_sum.encode())
                get_message= clientSocket.recv(GET_RECV).decode()
                if re.search(rf'{ERROR_MESSAGE[4]}', get_message):
                    print("Login success for the app")
                    work_app = True
                    passward_for_html = passward
                    name_for_html = name
                else:
                    print("Login failed for the app")
                    work_app = False
                match = re.search(r'id":(\d+)', get_message)
                if match:
                    glit_id = match.group(1)
                print("your id:",glit_id)
                flag_app = False

        name_for_html,passward_for_html = name,passward
        work_html,id_user,sparkle_cookie = swissknife.login_and_fetch_data(name_for_html, passward_for_html)
        flag = True

        while work_html == False and flag:
            print("there is no account in web")
            want = input("do you want to get with web(y/n):")
            if want == 'y':
                name_for_html,passward_for_html = swissknife.login_info()
                work_html,id_user,sparkle_cookie = swissknife.login_and_fetch_data(name_for_html, passward_for_html)
            else:
                print(":(")
                flag = False


        while work_app or work_html:
            swissknife.menu_app()
            swissknife.menu_html()
            swissknife.chalnges()
            choice = int(input("Enter your choice: "))
            if choice == 1 and work_app:
                data = input("Enter search data: ")
                swissknife.search_bug(clientSocket, data)
            elif choice == 2 and work_app:
                name = input("Enter display name: ")
                swissknife.change_display_name(clientSocket, name, glit_id)
            elif choice == 3 and work_app:
                year = int(input("Enter year: "))
                swissknife.post_with_changed_year(clientSocket, year, name, glit_id)
            elif choice == 4 and work_app:
                swissknife.like_spam(clientSocket, name, glit_id)
            elif choice == 5 and work_app:
                swissknife.login_feed_info_disclosure(clientSocket, glit_id)
            elif choice == 6 and work_app:
                swissknife.send_follow_to_yourself(clientSocket, glit_id)
            elif choice == 7 and work_app:
                swissknife.connection_between_people(clientSocket, glit_id)
            elif choice == 8 and work_app:
                swissknife.update(clientSocket)
            elif choice == 9 and work_app:
                swissknife.user_info_app(clientSocket)
            elif choice == 10 and work_html:
                swissknife.users(sparkle_cookie)
            #challanges
            elif choice == 11 and work_app:
                glit_id,name,passward = swissknife.Login_challange(clientSocket, glit_id)
                if glit_id == None:
                    work_app = False
                    work_html = False
                    print("loginout..")
                    swissknife.logout_html(glit_id, sparkle_cookie)
                    swissknife.logout(clientSocket, glit_id)
                    clientSocket.close()
            elif choice == 12 and work_html:
                swissknife.challange_password(glit_id, sparkle_cookie)
            elif choice == 13 and work_app:
                swissknife.privacy_challenge(clientSocket)
            elif choice == 14 and work_html:
                swissknife.xsrf_challange(name_for_html, id_user, sparkle_cookie)
            else:
                work_app = False
                work_html = False
                print("try to logout.. from app and web")
                swissknife.logout_html(glit_id, sparkle_cookie)
                swissknife.logout(clientSocket, glit_id)
                clientSocket.close()
    except Exception as e:
        print(e)
        if work_app:
            print("try to logout.. from app")
            swissknife.logout(clientSocket, glit_id)
        if work_html:
            print("try to logout.. from web")
            swissknife.logout_html(id_user, sparkle_cookie)

        clientSocket.close()



if __name__ == "__main__":
    main()
