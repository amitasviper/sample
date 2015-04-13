import Adafruit_BBIO.GPIO as GPIO
import time

red_1="P8_11"
green_1="P8_13"
yellow_1="P8_12"

red_2="P8_14"
green_2="P8_15"
yellow_2="P8_16"


red_3="P9_11" 
green_3="P9_14" 
yellow_3="P9_12"

red_4="P9_30"
green_4="P9_27"
yellow_4="P9_26"
    
    
GPIO.setup(red_1,GPIO.OUT)
GPIO.setup(green_1,GPIO.OUT) 
GPIO.setup(yellow_1,GPIO.OUT)
    
GPIO.setup(red_2,GPIO.OUT)
GPIO.setup(green_2,GPIO.OUT)
GPIO.setup(yellow_2,GPIO.OUT)

GPIO.setup(red_3,GPIO.OUT)
GPIO.setup(green_3,GPIO.OUT)
GPIO.setup(yellow_3,GPIO.OUT)

GPIO.setup(red_4,GPIO.OUT)
GPIO.setup(green_4,GPIO.OUT)
GPIO.setup(yellow_4,GPIO.OUT)

n=20
while n>0:
####################GREEN1#################
        GPIO.output(green_1,GPIO.HIGH)
        GPIO.output(red_2,GPIO.HIGH)
        GPIO.output(red_3,GPIO.HIGH)
        GPIO.output(red_4,GPIO.HIGH)
        time.sleep(5)
        GPIO.output(green_1,GPIO.LOW)
        GPIO.output(red_2,GPIO.LOW)
        GPIO.output(red_3,GPIO.LOW)
        GPIO.output(red_4,GPIO.LOW)


        GPIO.output(yellow_1,GPIO.HIGH)
        GPIO.output(yellow_2,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(yellow_1,GPIO.LOW)
        GPIO.output(yellow_2,GPIO.LOW)

####################GREEN2#################
        GPIO.output(green_2,GPIO.HIGH)
        GPIO.output(red_1,GPIO.HIGH)
        GPIO.output(red_3,GPIO.HIGH)
        GPIO.output(red_4,GPIO.HIGH)
        time.sleep(5)
        GPIO.output(green_2,GPIO.LOW)
        GPIO.output(red_1,GPIO.LOW)
        GPIO.output(red_3,GPIO.LOW)
        GPIO.output(red_4,GPIO.LOW)

        GPIO.output(yellow_2,GPIO.HIGH)
        GPIO.output(yellow_3,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(yellow_2,GPIO.LOW)
        GPIO.output(yellow_3,GPIO.LOW)

####################GREEN3#################
        GPIO.output(green_3,GPIO.HIGH)
        GPIO.output(red_1,GPIO.HIGH)
        GPIO.output(red_2,GPIO.HIGH)
        GPIO.output(red_4,GPIO.HIGH)
        time.sleep(5)
        GPIO.output(green_3,GPIO.LOW)
        GPIO.output(red_1,GPIO.LOW)
        GPIO.output(red_2,GPIO.LOW)
	GPIO.output(red_4,GPIO.LOW)

        GPIO.output(yellow_3,GPIO.HIGH)
        GPIO.output(yellow_4,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(yellow_3,GPIO.LOW)
        GPIO.output(yellow_4,GPIO.LOW)


####################GREEN4#################
        GPIO.output(green_4,GPIO.HIGH)
        GPIO.output(red_1,GPIO.HIGH)
        GPIO.output(red_3,GPIO.HIGH)
        GPIO.output(red_2,GPIO.HIGH)
        time.sleep(5)
        GPIO.output(green_4,GPIO.LOW)
        GPIO.output(red_1,GPIO.LOW)
        GPIO.output(red_3,GPIO.LOW)
        GPIO.output(red_2,GPIO.LOW)

        GPIO.output(yellow_1,GPIO.HIGH)
        GPIO.output(yellow_4,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(yellow_1,GPIO.LOW)
        GPIO.output(yellow_4,GPIO.LOW)
	n = n-1


