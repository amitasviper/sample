import Adafruit_BBIO.GPIO as GPIO

while True:
	port = "P8_"
	print "enter port num"
	temp = raw_input()
	port += temp
	GPIO.setup(port, GPIO.OUT)
	while True:
		print "1. high 2.low 3.exit"
		temp = input()
		if temp == 1:
			GPIO.output(port, GPIO.HIGH)
		if temp == 2:
			GPIO.output(port, GPIO.LOW)
		if temp == 3:
			break;
