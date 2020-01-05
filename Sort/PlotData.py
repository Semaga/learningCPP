import numpy as np
import matplotlib.pyplot as plt

RawFile = "dRawFile.txt"
SortFile = "SortData.txt"

with open(RawFile) as Read:
    r = Read.readline()
r = r.split()    
with open(SortFile) as Read:
    a = Read.readline()
a = a.split()
lenght = len(a)
data1 = np.zeros((lenght), int)
data2 = np.zeros((lenght), int)

for i, value in enumerate(r):
    data1[i] = int(value)
for i, value in enumerate(a):
    data2[i] = int(value)    

plt.figure()
plt.subplot(121)
plt.xlabel("Index")
plt.ylabel("Value")
plt.title("Before sort")
plt.yscale('log')
plt.plot(data1)

plt.subplot(122)
plt.title("After sort")
plt.xlabel("Index")
plt.yscale('log')
plt.plot(data2)

plt.show()