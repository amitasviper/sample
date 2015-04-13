import sys
import time
import Adafruit_BBIO.GPIO as GPIO

pin1 = "P8_13"
pin2 = "P8_14"
pin3 = "P8_7"
pin4 = "P8_16"


def stepperExit ():
        print "Exited"
        return 
        
def stepperInit ():
        global pin1, pin2, pin3, pin4
        GPIO.setup(pin1,GPIO.OUT)
        GPIO.setup(pin2,GPIO.OUT)
        GPIO.setup(pin3,GPIO.OUT)
        GPIO.setup(pin4,GPIO.OUT)
        return        
def stepperOn(pinNo):
        GPIO.output(pinNo,GPIO.HIGH)

def stepperOff(pinNo):
        GPIO.output(pinNo,GPIO.LOW)


def stepperSeq5():
        stepperOn(pin1)
        time.sleep(0.0001)
        stepperOff(pin2)
        time.sleep(0.0001)
        stepperOn(pin3)
        time.sleep(0.0001)
        stepperOff(pin4)
        time.sleep(0.0001)
        return 



def stepperSeq9():
        stepperOn(pin1)
        time.sleep(0.0001)
        stepperOff(pin2)
        time.sleep(0.0001)
        stepperOff(pin3)
        time.sleep(0.0001)
        stepperOn(pin4)
        time.sleep(0.0001)
        return 


def stepperSeq10():
        stepperOff(pin1)
        time.sleep(0.0001)
        stepperOn(pin2)
        time.sleep(0.0001)
        stepperOff(pin3)
        time.sleep(0.0001)
        stepperOn(pin4)
        time.sleep(0.0001)
        return 



def stepperSeq6():
        stepperOff(pin1)
        time.sleep(0.0001)
        stepperOn(pin2)
        time.sleep(0.0001)
        stepperOn(pin3)
        time.sleep(0.0001)
        stepperOff(pin4)
        time.sleep(0.0001)
        return 


        
def stepperDirLeft():
        stepperSeq5()
        time.sleep(0.01)
        stepperSeq9()
        time.sleep(0.01)
        stepperSeq10()
        time.sleep(0.01)
        stepperSeq6()
        time.sleep(0.01)
        return



def stepperDirRight():
        stepperSeq6()
        time.sleep(0.01)
        stepperSeq10()
        time.sleep(0.01)
        stepperSeq9()
        time.sleep(0.01)
        stepperSeq5()
        time.sleep(0.01)
        return


try:
        print "\nStepper Motor Driver using Python\n"
        print  "-----------------------------------------------\n"      
        stepperInit()
        while True:
                choice = int(raw_input("1.Anticlockwise 2. Clockwise 3.EXIT : "))
                if choice == 1:
                        for i in range(0, 50):
                                stepperDirLeft()
                elif choice == 2:
                        for i in range(0, 50):
                                stepperDirRight()
                elif choice == 3:
                        break
                else:
                        print "Invalid choice"
except KeyboardInterrupt:
        stepperExit()        
        print "Program Exit due to CTRL-C"
        sys.exit(0)


