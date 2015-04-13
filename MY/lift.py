import Adafruit_BBIO.GPIO as GPIO
import time
from threading import Thread

dest=[]
src=[]
curr=0

def remove_values_from_list(the_list, val):
   return [value for value in the_list if value != val]

def displayled(curr):
        if curr==0:
                GPIO.output(red0,GPIO.LOW)
                GPIO.output(green0,GPIO.HIGH)
                time.sleep(4)
                GPIO.output(red0,GPIO.HIGH)
                GPIO.output(green0,GPIO.LOW)
        if curr==1:
                GPIO.output(red1,GPIO.LOW)
                GPIO.output(green1,GPIO.HIGH)
                time.sleep(4)
                GPIO.output(red1,GPIO.HIGH)
                GPIO.output(green1,GPIO.LOW)

        if curr==2:
                GPIO.output(red2,GPIO.LOW)
                GPIO.output(green2,GPIO.HIGH)
                time.sleep(4)
                GPIO.output(red2,GPIO.HIGH)
                GPIO.output(green2,GPIO.LOW)
        if curr==3:
                GPIO.output(red3,GPIO.LOW)
                GPIO.output(green3,GPIO.HIGH)
                time.sleep(4)
                GPIO.output(red3,GPIO.HIGH)
                GPIO.output(green3,GPIO.LOW)


def display(num):
        if num==0:
                GPIO.output(a,GPIO.HIGH)
                GPIO.output(b,GPIO.HIGH)
                GPIO.output(c,GPIO.HIGH)
                GPIO.output(d,GPIO.HIGH)
                GPIO.output(e,GPIO.HIGH)
                GPIO.output(f,GPIO.HIGH)
                GPIO.output(g,GPIO.LOW)
        if num==1:
                GPIO.output(a,GPIO.LOW)
                GPIO.output(b,GPIO.HIGH)
                GPIO.output(c,GPIO.HIGH)
                GPIO.output(d,GPIO.LOW)
                GPIO.output(e,GPIO.LOW)
                GPIO.output(f,GPIO.LOW)
                GPIO.output(g,GPIO.LOW)

        if num==2:
                GPIO.output(a,GPIO.HIGH)
                GPIO.output(b,GPIO.HIGH)
                GPIO.output(c,GPIO.LOW)
                GPIO.output(d,GPIO.HIGH)
                GPIO.output(e,GPIO.HIGH)
                GPIO.output(f,GPIO.LOW)
                GPIO.output(g,GPIO.HIGH)

        if num==3:
                GPIO.output(a,GPIO.HIGH)
                GPIO.output(b,GPIO.HIGH)
                GPIO.output(c,GPIO.HIGH)
                GPIO.output(d,GPIO.HIGH)
                GPIO.output(e,GPIO.LOW)
                GPIO.output(f,GPIO.LOW)
                GPIO.output(g,GPIO.HIGH)

def accept():
        global dest
        global src
        while 1:
                print "Enter 1 to call the lift and 2 to enter dest"
                ch=input()
                if ch==1:
                        print "enter the floor number"
                        floor=input()
                        if floor <0 or floor >3:
                                print "Invalid choice"
                                continue
                        else:
                                src.append(floor)
                elif ch==2:
                        print "Enter the destination floor"

                        floor=input()
                        if floor<0 or floor>3:
                                print "Invalid choice"
                                continue
                        else:
                                dest.append(floor)


def movement():
        global dest
        global src
        global curr

        GPIO.output(red0,GPIO.HIGH)
        GPIO.output(red1,GPIO.HIGH)
        GPIO.output(red2,GPIO.HIGH)
        GPIO.output(red3,GPIO.HIGH)


        while 1:

                if len(dest)>0:
                        print "in if"
                        z=dest[0]
                        dest.pop(0)
                        if z<curr:
                                while(curr!=z):
                                        display(curr)
                                        if curr in src or curr in dest:
                                                src=remove_values_from_list(src,curr)
                                                dest=remove_values_from_list(dest,curr)
                                                displayled(curr)

                                        curr-=1
                                display(curr)
                                time.sleep(1)
                                displayled(curr)
                        elif z>curr:
                                while(curr!=z):
                                        display(curr)
                                        if curr in src or curr in dest:
                                                src=remove_values_from_list(src,curr)
                                                dest=remove_values_from_list(dest,curr)
                                                displayled(curr)

                                        curr+=1
                                display(curr)
                                time.sleep(1)
                                displayled(curr)
                elif len(src)>0:
                        print "in else"
                        z=src[0]
                        src.pop(0)
                        if z<curr:
                                while(curr!=z):
                                        display(curr)
                                        if curr in src or curr in dest:
                                                src=remove_values_from_list(src,curr)
                                                dest=remove_values_from_list(dest,curr)
                                                displayled(curr)

                                        curr-=1
                                display(curr)
                                time.sleep(1)
                                displayled(curr)
                        elif z>curr:
                                print "in elif"
                                while(curr!=z):
                                        display(curr)
                                        time.sleep(2)
                                        if curr in src or curr in dest:
                                                src=remove_values_from_list(src,curr)
                                                dest=remove_values_from_list(dest,curr)
                                                displayled(curr)

                                        curr+=1
                                display(curr)
                                time.sleep(1)
                                displayled(curr)


green0="P8_7"
red0="P8_8"
red1="P8_9"
green1="P8_10"
red2="P8_11"
green2="P8_12"
red3="P8_13"
green3="P8_14"

a="P9_11"
b="P9_12"
c="P9_13"
d="P9_14"
e="P9_15"
f="P9_16"
g="P9_21"

GPIO.setup(green0,GPIO.OUT)
GPIO.setup(red0,GPIO.OUT)

GPIO.setup(green1,GPIO.OUT)
GPIO.setup(red1,GPIO.OUT)

GPIO.setup(green2,GPIO.OUT)
GPIO.setup(red2,GPIO.OUT)

GPIO.setup(green3,GPIO.OUT)
GPIO.setup(red3,GPIO.OUT)

GPIO.setup(a,GPIO.OUT)
GPIO.setup(b,GPIO.OUT)
GPIO.setup(c,GPIO.OUT)
GPIO.setup(d,GPIO.OUT)
GPIO.setup(e,GPIO.OUT)
GPIO.setup(f,GPIO.OUT)
GPIO.setup(g,GPIO.OUT)


ac=Thread(target=accept,args=())
mov_lift=Thread(target=movement,args=())

ac.start()
mov_lift.start()

ac.join()
mov_lift.join()



