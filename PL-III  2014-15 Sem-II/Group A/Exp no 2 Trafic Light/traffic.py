import Adafruit_BBIO.GPIO as GPIO

import time

red_1 = "P8_15"
green_1 = "P8_17"
yellow_1 = "P8_19"

red_2 = "P8_9"
green_2 = "P8_4"
yellow_2 = "P8_7"

#red_3 = "P9_"
#green_3 = "P9_"
#yellow_3 = "P9_"

#red_4 = "P9_"
#green_4 = "P9_"
#yellow_4 = "P9_"

GPIO.setup(red_1,GPIO.OUT)
GPIO.setup(green_1,GPIO.OUT)
GPIO.setup(yellow_1,GPIO.OUT)
GPIO.setup(red_2,GPIO.OUT)
GPIO.setup(green_2,GPIO.OUT)
GPIO.setup(yellow_2,GPIO.OUT)



GPIO.output(red_1,GPIO.HIGH)
GPIO.output(yellow_1,GPIO.HIGH)
GPIO.output(green_1,GPIO.HIGH)
GPIO.output(red_2,GPIO.HIGH)
GPIO.output(yellow_2,GPIO.HIGH)
GPIO.output(green_2,GPIO.HIGH)
time.sleep(5)
#GPIO.output(red_2,GPIO.HIGH)
#GPIO.output(yellow_2,GPIO.HIGH)
#GPIO.output(green_2,GPIO.HIGH)
time.sleep(2)
