import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

datosIniciales=np.genfromtxt("condicionesI.txt",delimiter=" ")
datosNormal=np.genfromtxt("Normal.txt",delimiter=" ")
x1=np.linspace(0.,50.,50)
y1=np.linspace(0.,50.,50)




fig = plt.figure(figsize = (7,7))
ax = fig.add_subplot(1,1,1, projection ='3d')
ax.plot_wireframe(x1,y1,datosNormal, rstride=2, cstride=2,cmap='Blues')
plt.show()
#plt.savefig('')
