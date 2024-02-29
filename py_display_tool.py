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
plt.title('Graph t(N) for sum search on worst')
plt.ylabel('time, nanoseconds')
plt.xlabel('number of elements in an array')
plt.show()