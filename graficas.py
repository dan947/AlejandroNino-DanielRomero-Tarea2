import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


datos=np.genfromtxt("euler.dat")

r=np.array([10,60,120])
plt.annotate("t= "+str(datos[0,1]),xy=(10,datos[0,0]),xytext=(5,datos[0,0]+1))
plt.annotate("t= "+str(datos[1,1]),xy=(60,datos[1,0]),xytext=(55,datos[1,0]+1))
plt.annotate("t= "+str(datos[2,1]),xy=(100,datos[2,0]),xytext=(115,datos[2,0]+1))


plt.title("Rho vs r")
plt.xlabel("Radios")
plt.ylabel("Densidades promedio")
plt.scatter(r,datos[:,0])
plt.savefig("Sedov.pdf")
plt.show()
