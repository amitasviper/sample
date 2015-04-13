import matplotlib.pyplot as plt
import numpy as np
import time
import psutil

import os
import thread

#fig = plt.figure()
#ax = fig.add_subplot(111)

#x = [1,2,3,4,5,6,7,8,9,10]

x = np.arange(20)

y = [0] * 20

plt.ion()
plt.show()


#plt2.ion()
#plt2.show()
def freqFunc(num):
	os.system('watch -n 0.5 "cat /proc/cpuinfo | grep -i MHz"')


thread.start_new_thread(freqFunc,(1,))
while True:

	
	#li, = ax.plot(x,y)
	plt.plot(x,y,lw=2)
	#plt2.plot(x,y,lw=2)
	y.remove(y[0])
	y.append( psutil.cpu_percent(interval=0.1))
	#print x
	#print y
	
	#plt2.xlabel("Time")
	#plt2.ylabel("Freq")
	#plt2.draw()

	#fig.canvas.draw()
	plt.xlabel("Time")
	plt.ylabel("CPU Usage")
	plt.draw()
	time.sleep(0.01)
	plt.cla()
	#plt2.cla()

	#time.sleep(10)
