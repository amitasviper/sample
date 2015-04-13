import Adafruit_BBIO.GPIO as GPIO
import time

red_1="P9_11"
yellow_1="P9_12"
green_1="P9_13"

red_2="P9_14"
yellow_2="P9_15"
green_2="P9_16"

red_3="P8_7"
yellow_3="P8_8"
green_3="P8_9"

red_4="P8_10"
yellow_4="P8_11"
green_4="P8_12"

GPIO.setup(red_1,GPIO.OUT)
GPIO.setup(yellow_1,GPIO.OUT)
GPIO.setup(green_1,GPIO.OUT)

GPIO.setup(red_2,GPIO.OUT)
GPIO.setup(yellow_2,GPIO.OUT)
GPIO.setup(green_2,GPIO.OUT)

GPIO.setup(red_3,GPIO.OUT)
GPIO.setup(yellow_3,GPIO.OUT)
GPIO.setup(green_3,GPIO.OUT)

GPIO.setup(red_4,GPIO.OUT)
GPIO.setup(yellow_4,GPIO.OUT)
GPIO.setup(green_4,GPIO.OUT)



flag=5
while flag:
        flag-=1
        GPIO.output(green_1,GPIO.HIGH)
        GPIO.output(red_2,GPIO.HIGH)
        GPIO.output(red_3,GPIO.HIGH)
        GPIO.output(red_4,GPIO.HIGH)
        time.sleep(8)
        GPIO.output(red_2,GPIO.LOW)
        GPIO.output(yellow_2,GPIO.HIGH)
        time.sleep(2)
        GPIO.output(green_1,GPIO.LOW)
        GPIO.output(red_1,GPIO.HIGH)
        GPIO.output(yellow_2,GPIO.LOW)
        GPIO.output(green_2,GPIO.HIGH)
        time.sleep(8)
        GPIO.output(red_3,GPIO.LOW)
        GPIO.output(yellow_3,GPIO.HIGH)
        time.sleep(2)
        GPIO.output(green_2,GPIO.LOW)
        GPIO.output(red_2,GPIO.HIGH)
        GPIO.output(yellow_3,GPIO.LOW)
        GPIO.output(green_3,GPIO.HIGH)
        time.sleep(8)
        GPIO.output(red_4,GPIO.LOW)
        GPIO.output(yellow_4,GPIO.HIGH)
        time.sleep(2)
        GPIO.output(green_3,GPIO.LOW)
        GPIO.output(red_3,GPIO.HIGH)
        GPIO.output(yellow_4,GPIO.LOW)
        GPIO.output(green_4,GPIO.HIGH)
        time.sleep(8)
        GPIO.output(red_1,GPIO.LOW)
        GPIO.output(yellow_1,GPIO.HIGH)
        time.sleep(2)
        GPIO.output(green_4,GPIO.LOW)
        GPIO.output(yellow_1,GPIO.LOW)