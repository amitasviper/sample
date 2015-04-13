import RPi.GPIO as GPIO
import time
import thread
a = 19
b = 7
c = 15
d = 13
e = 11
f = 21
g = 23
green = 18
red = 16
blinking  = 24
push1 = 26

total_floor = 9

started = 0
dest_floor = -1
current_floor = 0
floor_count = 0

prevTime = 0
endTime = 0
stops = []

def initialise():
	GPIO.setmode(GPIO.BOARD)
	valueOut = [a,b,c,d,e,f,g,green,red,blinking]
	for x in valueOut:
		GPIO.setup(x,GPIO.OUT)

	GPIO.setup(push1,GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

def clearAll():
	high = [a,b,c,d,e,f,g]
	for x in high:
		GPIO.output(x,GPIO.HIGH)

def glowZero():
	clearAll()
	low = [a,b,c,d,e,f]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def glowOne():
	clearAll()
	low = [b,c]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def glowTwo():
	clearAll()
	low = [a,b,g,e,d]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def glowThree():
	clearAll()
	low = [a,b,g,c,d]
	for x in low:
		GPIO.output(x,GPIO.LOW)
	
def glowFour():
	clearAll()
	low = [f,g,b,c]
	for x in low:
		GPIO.output(x,GPIO.LOW)
	
def glowFive():
	clearAll()
	low = [a,f,g,c,d]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def glowSix():
	clearAll()
	low = [a,f,g,e,d,c]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def glowSeven():
	clearAll()
	low = [a,b,c]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def glowEight():
	clearAll()
	low = [a,b,c,d,e,f,g]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def glowNine():
	clearAll()
	low = [a,b,f,g,c,d]
	for x in low:
		GPIO.output(x,GPIO.LOW)

def openDoor():
	GPIO.output(green,GPIO.HIGH)
	GPIO.output(red,GPIO.LOW)
	print "Door opened %%%%%%%%%%%%%%"
	#time.sleep(4)
def closeDoor():
	GPIO.output(green, GPIO.LOW)
	GPIO.output(red, GPIO.HIGH)

def buttonHandler(channel):
	print "Button Pressed"
	global dest_floor, floor_count, prevTime,endTime,stops
	if started == 0:
		if dest_floor < total_floor:
			dest_floor += 1
			floor_count = abs(current_floor - dest_floor)
			closeDoor()

	else:
		if len(stops) == 0:
			prevTime = time.time()
			stops.append(0)

		else:
			endTime = time.time()
			if endTime - prevTime < 2:
				stops[len(stops)-1] += 1
				prevTime = endTime
				print "User increamented New Floor No:",stops[len(stops)-1]
			else:
				stops.append(0)
				print "User ADDED new floor :"
				prevTime = endTime

def blinkingLed():
	global blinking
	while True:
		GPIO.output(blinking,GPIO.HIGH)
		time.sleep(0.05)
		GPIO.output(blinking,GPIO.LOW)
		time.sleep(0.05)

if __name__ == "__main__":
	initialise()
	floor = 0
	request = 0
	caller = ["zero","one","two","three","four","five","six","seven","eight","nine"]
	functions = {"zero":glowZero,"one":glowOne, "two":glowTwo, "three":glowThree, "four":glowFour, "five":glowFive, "six":glowSix,"seven":glowSeven,"eight":glowEight,"nine":glowNine}
	GPIO.add_event_detect(push1,GPIO.RISING,callback=buttonHandler, bouncetime=300)
	glowZero()
	thread.start_new_thread(blinkingLed,())
	while True:
		if current_floor != dest_floor and dest_floor != -1:
			print "got inside"
			time.sleep(7)
			started = 1
			print "$$$$ initial current_floor ",current_floor," dest_floor ",dest_floor
			while current_floor != dest_floor:
				print "Stops list: ",stops
				print "Sleeping :count: ",floor_count
				print "On floor No: ",current_floor," dest: ",dest_floor
				if current_floor in stops:
					functions[caller[current_floor]]()
					openDoor()
					print "Opening door in between"
					time.sleep(10)
					stops.remove(current_floor)
					closeDoor()

				if current_floor < dest_floor:
					functions[caller[current_floor]]()
					floor_count -= 1
					current_floor += 1
				else:
					functions[caller[current_floor]]()
					floor_count -= 1
					current_floor -= 1
				
				time.sleep(7)
			
			functions[caller[current_floor]]()
			print "opening door at floor_count ",floor_count
			openDoor()
			floor_count = 0
			dest_floor = -1
			started = 0
