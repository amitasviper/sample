import RPi.GPIO as GPIO
from threading import Thread

freq = 1
dutyCycle = 50
p = 0

def takeInput():
	global freq, dutyCycle, p
	while(True):
		choice = int(raw_input("1.Change Frequency 2.Change DutyCycle 3.EXIT: "))
		if choice == 1:
			freq = int(raw_input("Enter Frequency: "))
			p.ChangeFrequency(freq)
		elif choice == 2:
			dutyCycle = int(raw_input("Enter Duty Cycle: "))
			p.ChangeDutyCycle(dutyCycle)
		elif choice == 3:
			break
		else:
			print "Invalid choice! Try Again"

if __name__ == "__main__":

	GPIO.setmode(GPIO.BOARD)
	pin = 7
	GPIO.setup(pin, GPIO.OUT)

	p = GPIO.PWM(pin, freq)

	p.start(dutyCycle)

	t1 = Thread(target=takeInput,args=())
	t1.start()
	t1.join()
	GPIO.cleanup()
