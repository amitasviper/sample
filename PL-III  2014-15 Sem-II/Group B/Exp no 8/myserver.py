import socket
import threading  
import time
import random

def handleConnection(clientSocket,address):
	data=""
	mtu=15
	data=clientSocket.recv(1024)
	if data == "REQ":
		print "--Request packat is received from client---" 
		time.sleep(3)
		flag =random.randrange(10)
		if flag<2:
			print "Revoking Permission"
			time.sleep(3)
			clientSocket.sendall("sorry")
		else:
			print "permission granted"
			time.sleep(3)
			clientSocket.sendall("GO AHEAD")
			time.sleep(3)
			while True:
				data = clientSocket.recv(8192)
				if len (data) > mtu:
					print "--buffer overflow--"
					clientSocket.sendall("--reduce transmission rate--")
				elif data =='q':
					clientSocket.sendall("Bye")
				else:
					clientSocket.sendall(data)
			print address[0],"left the system\n"
	else:
		print "permission denied"
	clientSocket.close()

def startServer(ip,port):
	sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	sock.bind((ip,port))
	sock.listen(5)
			
	print "server started on port:",port,"\n"	
	while True:
		newSock,address = sock.accept()
		print "\n",address[0]," connected "
		handler = threading.Thread(target=handleConnection,args=(newSock,address))
		handler.start()

			



if __name__ == "__main__":

	startServer("",5555)

