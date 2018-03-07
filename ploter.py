## esasharahi@gmail.com
#!/usr/bin/python
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt


fig2d = plt.figure()



with open('points.txt') as f_1:
	lines = f_1.readlines()
	x1 = [line.split()[0] for line in lines]
	y1 = [line.split()[1] for line in lines]

with open('gradient.txt') as f_2:
	lines = f_2.readlines()
	x2 = [line.split()[0] for line in lines]
	y2 = [line.split()[1] for line in lines]




ax = fig2d.add_subplot(1, 1, 1)
ax.plot(x1, y1, c = 'red', label = '$points$')
ax.plot(x2, y2, c = 'blue', label = '$gradient$')
leg = ax.legend()
ax.set_title("Gradient of some points")
ax.set_xlabel('$x$')
ax.set_ylabel('$y$')





fig2d.savefig('2D_gradient.eps', format='eps', dpi=1000)

plt.show()
