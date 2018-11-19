import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


datos=np.genfromtxt("45.txt",delimiter=" ")

plt.plot(datos[:143,0],datos[:143,1])
plt.show()
