import Adafruit_BBIO.PWM as PWM
from threading import Thread

freq = 1
dutyCycle = 5
pin="P9_14"
def takeInput():
        global freq, dutyCycle, pin
        while(True):
                choice = int(raw_input("1.Change Frequency 2.Change DutyCycle 3.EXIT: "))
                if choice == 1:
                        freq = int(raw_input("Enter Frequency: "))
                        PWM.set_frequency(pin,freq)
                elif choice == 2:
                        dutyCycle = int(raw_input("Enter Duty Cycle: "))
                        PWM.set_duty_cycle(pin,dutyCycle)
                elif choice == 3:
                        break
                else:
                        print "Invalid choice! Try Again"

if __name__ == "__main__":
        global pin

        print "pin:",pin
        PWM.start(pin,50)

        t1 = Thread(target=takeInput,args=())
        t1.start()
        t1.join()
