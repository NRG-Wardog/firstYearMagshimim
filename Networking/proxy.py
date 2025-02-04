import socket

PORT = 9090
SERVER_PORT = 92
SERVER_IP = 'ip'

def main():
    # Create a socket for the proxy server
    proxy_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    proxy_socket.bind(('', PORT))
    proxy_socket.listen(1)

    while True:
        # Create a socket to connect to the destination server
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_address = (SERVER_IP, SERVER_PORT)
        sock.connect(server_address)

        # Accept incoming connection from the client
        misag, client_address = proxy_socket.accept()
        print("Received request from client")

        # Receive data from the client
        data = misag.recv(1024)

        # Check if the request contains "France", if so, deny access
        if data.decode().find("France") != -1:
            misag.send(b"""ERROR# "France is banned!" """)
        else:
            # Forward the request to the destination server
            sock.send(data)
            print("Sent request to server")

            # Receive response from the server
            response = sock.recv(1024)

            # Modify the response before sending it back to the client
            modified_response = response.decode().replace("name:", "name:proxy ").replace("jpg", ".jpg").replace("SERVERERROR", "ERROR#")
            misag.send(modified_response.encode())
            print("Sent modified response to client")

        # Close connections
        misag.close()
        sock.close()

    proxy_socket.close()

if __name__ == '__main__':
    main()
