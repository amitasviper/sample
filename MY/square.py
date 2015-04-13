import Adafruit_BBIO.GPIO as GPIO
import time
from threading import Thread


led="P8_7"

GPIO.setup(led,GPIO.OUT)

freq=1.0

def takeinput():
        global freq
        while 1:
                print "Enter Frequency"
                freq=float(raw_input())

def show_wave():
        global freq
        while 1:
                GPIO.output(led,GPIO.HIGH)
                time.sleep(freq)
                GPIO.output(led,GPIO.LOW)
                time.sleep(freq)


led="P8_7"

GPIO.setup(led,GPIO.OUT)

t1=Thread(target=takeinput,args=())
t2=Thread(target=show_wave,args=())

t1.start()
t2.start()

