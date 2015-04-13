import socket
import time
from threading import Thread

class Connection:
	def __init__(self,ip,port):
		self.serverAddress=(ip,port)
		self.sock = socket.socket()

	def sendData(self):
		self.sock.connect(self.serverAddress)
		print "----sending request packat---"
		time.sleep(3)
		self.sock.sendall("REQ")
		data=self.sock.recv(1024)
		if(data == "GO AHEAD"):
			print "server ready to accept data"
			while True:
				userData = raw_input("\n Enter a string ('q' to quit)")
				self.sock.sendall(userData)
				echoReply = self.sock.recv(2048)
				print "server replied : ", echoReply
				if echoReply == "Bye":
					print "\n Performing cleanup"
					self.sock.close()
					print "socket closed \n"
					break
		else:
			print "server refused to recieve data"
				


if __name__=="__main__":

	ip=raw_input("enter ip address of server:")
	conn =Connection(ip,5555)
	conn.sendData()
