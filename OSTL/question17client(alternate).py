import socket

host = '127.0.0.1'
port = 9101

mySocket =socket.socket()
mySocket.connect((host,port))

message = input("->")



while message != 'q':
    mySocket.send(message.encode())
    data = mySocket.recv(1024).decode()
    print("recieved from user  ",str(data))
    message = input("->")

mySocket.close()
   