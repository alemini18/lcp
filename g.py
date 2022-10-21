import matplotlib.pyplot as plt
import math
import numpy as np



p=int(input())
for i in range(0,9):
    a=input().split()
    plt.plot(1/float(a[1]),int(a[0])/p,'bo')

x=[0,1000]
y=[1,1]
plt.xscale("log")
plt.yscale("log")
plt.xlabel("1/epsilon")
plt.ylabel("ratio")
plt.plot(x,y)
plt.show()
