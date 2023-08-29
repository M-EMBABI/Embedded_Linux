import socket
import threading

def handle_client(client_socket):
    while True:
        data = client_socket.recv(1024).decode('utf-8')
        if not data:
            break
        print("Received data from client:", data)
        
    client_socket.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', 5050))
    server.listen()
    print("enter your message: ")

    while True:
        client, addr = server.accept()
        print("New client connected:", addr)
        client_thread = threading.Thread(target=handle_client, args=(client,))
        client_thread.start()

start_server()
