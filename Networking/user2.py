import socket
import time
SERVER_PORT = 9090
SERVER_IP = '127.0.0.1'
BUFFER_SIZE = 1024
FORMAT = "69-"

def main():
    flag = True
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = (SERVER_IP, SERVER_PORT)
    try:
        print("trying to connect to the server")
        sock.connect(server_address)
        time.sleep(1)
        print("connection")
        walcome = sock.recv(BUFFER_SIZE).decode().split(FORMAT)[1]
        print(walcome)
        menu = walcome.replace((FORMAT+"Welcome\n"),"")
    except Exception:
        print("server offline")
        flag = False

    while flag:

        try:
            number = int(input("server requ:\nenter number: "))
            while(number<1 or number>8):
                number = int(input("server requ:\nenter number(1-8): "))
            if(number==1):
                sock.send((str(number)+","+"list of albums").encode())
                data = sock.recv(BUFFER_SIZE)
                print(data.decode().split("-")[1]+"\n")
            elif(number==2):
                album = input("server requ:\nenter album: ")
                sock.send((str(number)+","+album).encode())
                data = sock.recv(BUFFER_SIZE)
                print(data.decode().split("-")[1]+"\n")
            elif(number==3):
                song = input("server requ:\nenter song:")
                sock.send((str(number)+","+song).encode())
                data = sock.recv(BUFFER_SIZE)
                print("The lenge is:",data.decode().split("-")[1]+"\n")
            elif(number==4):
                song = input("server requ:\nenter song:")
                sock.send((str(number)+","+song).encode())
                data = sock.recv(BUFFER_SIZE)
                print("The words:\n",data.decode().split("-")[1]+"\n")
            elif(number==5):
                song = input("server requ:\nenter song:")
                sock.send((str(number)+","+song).encode())
                data = sock.recv(BUFFER_SIZE)
                print("The albom of the song is:",data.decode().split("-")[1]+"\n")
            elif(number==6):
                word = input("server requ:\nenter word:")
                sock.send((str(number)+","+word).encode())
                data = sock.recv(BUFFER_SIZE)
                print("songs having the word in there name:",data.decode().split("-")[1]+"\n")
            elif(number==7):
                word = input("server requ:\nenter word:")
                sock.send((str(number)+","+word).encode())
                data = sock.recv(BUFFER_SIZE)
                print("songs having the word:",data.decode().split("-")[1]+"\n")
            elif(number==8):
                flag = False
        except  Exception as e:
            print("write number only",e)

        print(menu)

    sock.close()

if __name__ == '__main__':
    main()
