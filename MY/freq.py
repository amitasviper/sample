import matplotlib.pyplot as plt
import numpy as np
import time,psutil,os,thread

x=np.arange(20)
y=[0]*20
plt.ion()
plt.show()

def func(num):
	os.system('watch -n 0.5 "cat /proc/cpuinfo | grep -i MHz"')
	

thread.start_new_thread(func,(1,))



while 1:
	plt.plot(x,y,lw=2)
	y.remove(y[0])
	y.append(psutil.cpu_percent(interval=0.1))

	plt.xlabel("Time")
	plt.ylabel("CPU Usage")
	plt.draw()
	time.sleep(0.01)
	plt.cla()



