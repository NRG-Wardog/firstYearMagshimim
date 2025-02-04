import socket
import select
import DATA

WORNG_INPUT = "wrong input option"
PORT = 9091
SERVER_IP = '127.0.0.1'
BUFFER_SIZE = 1024
RESPONED = "69-"
ERROR = "405-"
WELCOME = """Welcome\nmenu:\n1- List of albums\n2 - List of songs in the album\n3 - Getting the length of a song \n4 - Receiving lyrics of a song \n5 - In which album is the song?\n6 - Searching a song by name\n7 - Song search by lyrics in the song\n8 - Exit"""

def handle_client_request(client_socket):
    try:
        request =   client_socket.recv(BUFFER_SIZE).decode()
        if not request:
            return False

        request_parts = request.split(',')
        try:
            option = int(request_parts[0])
            data = request_parts[1] if len(request_parts) > 1 else ""
            response = RESPONED+DATA.play(option,data)
            print(response)
        except Exception as e:
            response = ERROR + WORNG_INPUT+ str(e)

        client_socket.send(response.encode())
        return True

    except Exception as e:
        print(e)
        response = ERROR + WORNG_INPUT + str(e)
        client_socket.send(response.encode())
        return False

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((SERVER_IP, PORT))
    server_socket.listen(5)
    print("Server is listening on", SERVER_IP, ":", PORT)

    inputs = [server_socket]
    outputs = []

    while inputs:
        try:
            readable, writable, exceptional = select.select(inputs, outputs, inputs)

            for s in readable:
                if s is server_socket:
                    try:
                        client_socket, addr = server_socket.accept()
                        client_socket.send((RESPONED + WELCOME).encode())
                        print("Connected by", addr)
                        inputs.append(client_socket)
                    except Exception as e:
                        print(f"Error accepting connection: {e}")

                else:
                    try:
                        if not handle_client_request(s):
                            inputs.remove(s)
                            s.close()
                    except Exception as e:
                        print(f"Error handling client request: {e}")
                        inputs.remove(s)
                        s.close()

            for s in exceptional:
                inputs.remove(s)
                if s in outputs:
                    outputs.remove(s)
                s.close()

        except Exception as e:
            print(f"Error in main loop: {e}")

    server_socket.close()

if __name__ == '__main__':
    main()
