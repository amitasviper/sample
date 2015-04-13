import Adafruit_BBIO.GPIO as GPIO
import time

red_1="P8_10"
green_1="P8_12"
yellow_1="P8_14"

red_2="P8_16"
green_2="P8_18"
yellow_2="P8_11"


GPIO.setup(red_1,GPIO.OUT)
GPIO.setup(green_1,GPIO.OUT)
GPIO.setup(yellow_1,GPIO.OUT)
GPIO.setup(red_2,GPIO.OUT)
GPIO.setup(green_2,GPIO.OUT)
GPIO.setup(yellow_2,GPIO.OUT)

n=20
while n>0:
        GPIO.output(red_1,GPIO.HIGH)
        GPIO.output(green_2,GPIO.HIGH)
        time.sleep(5)
        GPIO.output(red_1,GPIO.LOW)
        GPIO.output(green_2,GPIO.LOW)

        GPIO.output(yellow_1,GPIO.HIGH)
        GPIO.output(yellow_2,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(yellow_1,GPIO.LOW)
        GPIO.output(yellow_2,GPIO.LOW)

        GPIO.output(red_2,GPIO.HIGH)
        GPIO.output(green_1,GPIO.HIGH)
        time.sleep(5)
        GPIO.output(red_2,GPIO.LOW)
        GPIO.output(green_1,GPIO.LOW)

        GPIO.output(yellow_1,GPIO.HIGH)
        GPIO.output(yellow_2,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(yellow_1,GPIO.LOW)
        GPIO.output(yellow_2,GPIO.LOW)

        n=n-1
