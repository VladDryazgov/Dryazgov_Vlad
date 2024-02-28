import matplotlib.pyplot as plt
import csv

X = []
Y = []

with open('data.csv', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=';')
    
    for ROWS in plotting:
        X.append(float(ROWS[0]))
        Y.append(float(ROWS[1]))

plt.plot(X, Y)
plt.title('Graph t(N) for current algorhythm')
plt.xlabel('time, nanoseconds')
plt.ylabel('number of elements in an array')
plt.show()