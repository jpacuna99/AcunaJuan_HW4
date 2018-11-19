import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

datosIniciales=np.genfromtxt("condicionesI.txt",delimiter=" ")
datosNormalInt1=np.genfromtxt("NormalInt1.txt",delimiter=" ")
datosNormalInt2=np.genfromtxt("NormalInt2.txt",delimiter=" ")
datosNormal=np.genfromtxt("Normalfinal.txt",delimiter=" ")


datosAbiertosInt1=np.genfromtxt("AbiertolInt1.txt",delimiter=" ")
datosAbiertosInt2=np.genfromtxt("AbiertoInt2.txt",delimiter=" ")
datosAbiertosFinal=np.genfromtxt("Abiertofinal.txt",delimiter=" ")

datosPeriodicosInt1=np.genfromtxt("PeridicolInt1.txt",delimiter=" ")
datosPeriodicosInt2=np.genfromtxt("PeriodicoInt2.txt",delimiter=" ")
datosPeriodicosFinal=np.genfromtxt("Periodicofinal.txt",delimiter=" ")




x1=np.linspace(0.,50.,50)
y1=np.linspace(0.,50.,50)
X,Y=np.meshgrid(x1,y1)



fig = plt.figure()
ax1 = fig.add_subplot(2,2,1, projection ='3d')
ax2= fig.add_subplot(2,2,2, projection ='3d')
ax3 = fig.add_subplot(2,2,3, projection ='3d')
ax4 = fig.add_subplot(2,2,4, projection ='3d')
ax1.set_title('Condiciones Inciales')
ax2.set_title('3000 Iteraciones')
ax3.set_title('6500 Iteraciones')
ax4.set_title('Final')

surf1=ax1.plot_surface(X,Y,datosIniciales,rstride=1,cstride=1, cmap="inferno",edgecolor="none")
surf2=ax2.plot_surface(X,Y,datosNormalInt1,rstride=1,cstride=1, cmap="inferno",edgecolor="none")
surf3=ax3.plot_surface(X,Y,datosNormalInt2,rstride=1,cstride=1, cmap="inferno")
surf4=ax4.plot_surface(X,Y,datosNormal,rstride=1,cstride=1, cmap="inferno")

m = cm.ScalarMappable(cmap="inferno")
m.set_array(datosIniciales)
plt.colorbar(m)

fig = plt.figure()
ax1 = fig.add_subplot(2,2,1, projection ='3d')
ax2= fig.add_subplot(2,2,2, projection ='3d')
ax3 = fig.add_subplot(2,2,3, projection ='3d')
ax4 = fig.add_subplot(2,2,4, projection ='3d')
ax1.set_title('Condiciones Inciales')
ax2.set_title('3000 Iteraciones')
ax3.set_title('6500 Iteraciones')
ax4.set_title('Final')


surf1=ax1.plot_surface(X,Y,datosIniciales,rstride=1,cstride=1, cmap="inferno",edgecolor="none")
surf2=ax2.plot_surface(X,Y,datosAbiertosInt1,rstride=1,cstride=1, cmap="inferno",edgecolor="none")
surf3=ax3.plot_surface(X,Y,datosAbiertosInt2,rstride=1,cstride=1, cmap="inferno")
surf4=ax4.plot_surface(X,Y,datosAbiertosFinal,rstride=1,cstride=1, cmap="inferno")

m = cm.ScalarMappable(cmap="inferno")
m.set_array(datosIniciales)
plt.colorbar(m)


fig = plt.figure()
ax1 = fig.add_subplot(2,2,1, projection ='3d')
ax2= fig.add_subplot(2,2,2, projection ='3d')
ax3 = fig.add_subplot(2,2,3, projection ='3d')
ax4 = fig.add_subplot(2,2,4, projection ='3d')
ax1.set_title('Condiciones Inciales')
ax2.set_title('3000 Iteraciones')
ax3.set_title('6500 Iteraciones')
ax4.set_title('Final')


surf1=ax1.plot_surface(X,Y,datosIniciales,rstride=1,cstride=1, cmap="inferno",edgecolor="none")
surf2=ax2.plot_surface(X,Y,datosPeriodicosInt1,rstride=1,cstride=1, cmap="inferno",edgecolor="none")
surf3=ax3.plot_surface(X,Y,datosPeriodicosInt2,rstride=1,cstride=1, cmap="inferno")
surf4=ax4.plot_surface(X,Y,datosPeriodicosFinal,rstride=1,cstride=1, cmap="inferno")

m = cm.ScalarMappable(cmap="inferno")
m.set_array(datosIniciales)
plt.colorbar(m)







datos=np.genfromtxt("45.txt",delimiter=" ")
print np.shape(datos)
plt.figure()
plt.plot(datos[:2000,0],datos[:2000,1],label="45")
plt.legend()
plt.ylim(0,)
plt.title("45 grados")
plt.figure()
plt.plot(datos[2000:4000,0],datos[2000:4000,1],c="b",label="10")

plt.plot(datos[4000:6000,0],datos[4000:6000,1],c="r",label="20")
plt.plot(datos[6000:8000,0],datos[6000:8000,1],c="g",label="30")
plt.plot(datos[8000:10000,0],datos[8000:10000,1],c="orange",label="40")
plt.plot(datos[10000:12000,0],datos[10000:12000,1],c="yellow",label="50")
plt.plot(datos[12000:14000,0],datos[12000:14000,1],c="brown",label="60")
plt.plot(datos[14000:16000,0],datos[14000:16000,1],c="gray",label="70")
plt.title("Varicion de grados")
plt.xlim(0.)
plt.ylim(0,)
plt.legend()
plt.show()




plt.show()
#plt.savefig('')
