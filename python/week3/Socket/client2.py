import socket
client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
ip=socket.gethostbyname(socket.gethostname())
print("your ip is: "+ip)
client.connect((ip,5050))
print("/////////////////////////////")
while True:
    msg=str(input("enter massage : "))
    msg_engode=msg.encode('UTF-8')
    client.send(msg_engode)
    print("///////////////////////////////")
    msg_len=client.recv(1024)
    print(f"{ip} ifsending to this message {msg_len.decode('UTF-8')}")
    client.close()
    
