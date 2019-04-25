import socket                   # Import socket module

s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
port = 60000                    # Reserve a port for your service.

s.connect((host, port))
s.send(b"Hello server!")

with open('client.txt', 'w') as f:
    print ('file opened')
    while True:
        print('receiving data...')
        data = s.recv(1024)
        print('data=%s', (data))
        if not data:
            break
        string1 = data.decode()
        # write data to a file
        f.write(sring1)

f.close()
print('Successfully get the file')
s.close()
print('connection closed')
