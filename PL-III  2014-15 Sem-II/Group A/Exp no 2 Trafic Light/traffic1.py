import Adafruit_BBIO.GPIO as GPIO
import time

red1 = "P8_11"
yellow1 = "P8_12"
green1 = "P8_13"

red2 = "P8_14"
yellow2 = "P8_15"
green2 = "P8_16"

def clearall():
	low = [red1, yellow1, green1, red2, yellow2, green2]
	for x in low:
		GPIO.output(x, GPIO.LOW)
		
def way1():
	clearall()
	GPIO.output(red2, GPIO.HIGH)
	GPIO.output(green1, GPIO.HIGH)
	time.sleep(8)
	GPIO.output(green1, GPIO.LOW)
	GPIO.output(yellow1, GPIO.HIGH)
	time.sleep(2)
	
def way2():
	clearall()
	GPIO.output(red1, GPIO.HIGH)
	GPIO.output(green2, GPIO.HIGH)
	time.sleep(8)
	GPIO.output(green2, GPIO.LOW)
	GPIO.output(yellow2, GPIO.HIGH)
	time.sleep(2)

GPIO.setup("P8_11", GPIO.OUT)
GPIO.setup("P8_12", GPIO.OUT)
GPIO.setup("P8_13", GPIO.OUT)

GPIO.setup("P8_14", GPIO.OUT)
GPIO.setup("P8_15", GPIO.OUT)
GPIO.setup("P8_16", GPIO.OUT)

while True:
	way1()
	way2()
