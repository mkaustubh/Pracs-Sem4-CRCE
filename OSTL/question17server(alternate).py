import socket

host = '127.0.0.1'
port = 9101

mySocket =socket.socket()
mySocket.bind((host,port))

mySocket.listen(1)
conn , addr =mySocket.accept()

print("Connection from  ",str(addr))

while True:
    data = conn.recv(1024).decode()
    if not data:
        break
    print("from connected use ",str(data))
    data = input("->")
    print("sending ",str(data))
    conn.send(data.encode())