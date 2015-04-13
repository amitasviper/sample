import Adafruit_BBIO.GPIO as GPIO
import threading
import thread
import time

def accept(queue):
	while True:
		print "Enter floor"
		floor=int(raw_input())
		if floor>4 or floor<1:
			print "Invalid Floor number"
		queue.append(floor)


floor1="P8_13"
floor2="P8_11"
floor3="P8_9"
floor4="P8_7"
floor = [floor1, floor2, floor3, floor4]

GPIO.setup(floor1,GPIO.OUT)
GPIO.setup(floor2,GPIO.OUT)
GPIO.setup(floor3,GPIO.OUT)
GPIO.setup(floor4,GPIO.OUT)

GPIO.output(floor[0], GPIO.LOW)
GPIO.output(floor[1], GPIO.LOW)
GPIO.output(floor[2], GPIO.LOW)
GPIO.output(floor[3], GPIO.LOW)

queue = []
current_floor = 1
GPIO.output(floor[current_floor-1], GPIO.HIGH)
ac=threading.Thread(target=accept,args=(queue,))
ac.start()
#thread.start_new_thread(accept,())

while 1:
	if queue.__len__() :
		print queue
		GPIO.output(floor[current_floor-1], GPIO.LOW)
		pre_floor = current_floor
		current_floor = queue[0]
		if current_floor > pre_floor:
			while pre_floor < current_floor:
				pre_floor += 1
				GPIO.output(floor[pre_floor-1], GPIO.HIGH)
				time.sleep(1)
				GPIO.output(floor[pre_floor-1], GPIO.LOW)
		else:
			while pre_floor > current_floor:
				pre_floor -= 1
				GPIO.output(floor[pre_floor-1], GPIO.HIGH)
				time.sleep(1)
				GPIO.output(floor[pre_floor-1], GPIO.LOW)

		queue.pop()
		GPIO.output(floor[current_floor-1], GPIO.HIGH)
		time.sleep(2)

