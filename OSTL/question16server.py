"""
Name    :Anup Joseph
Topic   :File Transfer
Roll no.:8351
"""
# server.py

import socket                   # Import socket module

port = 60000                    # Reserve a port for your service.
s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
s.bind((host, port))            # Bind to the port
s.listen(5)                     # Now wait for client connection.

print ('Server listening....')

while True:
    conn, addr = s.accept()     # Establish connection with client.
    print ('Got connection from', addr)
    data = conn.recv(1024)
    print('Server received', repr(data))

    filename='mytext.txt'
    f = open(filename,'r')
    l = f.read()
    bytes2 = l.encode()
    while (l):
       conn.send(bytes2)
       print('Sent ',repr(bytes2))
       l = f.read()
       bytes2 = l.encode()

    f.close()

    print('Done sending')
    conn.send(b'Thank you for connecting')
    conn.close()

