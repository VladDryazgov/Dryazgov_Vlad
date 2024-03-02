import matplotlib.pyplot as plt
import csv
import math

X = []
Y = []
i=320 #by digits (task;subtask;version) description written on the graphs
with open('data.csv', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=';')
    
    for ROWS in plotting:
        X.append(math.log(float(ROWS[0])))
        Y.append((float(ROWS[1])))
match i:
    case 110:
        plt.scatter(X[:100], Y[:100],color='b')
        plt.title('Graph t(N) for lin search on worst')
        plt.ylabel('time, nanoseconds')
        plt.xlabel('number of elements in an array')
    case 111:
        plt.scatter(X[:100], Y[:100],color='b')
        plt.title('Graph t(N) for lin search on avg')
        plt.ylabel('time, nanoseconds')
        plt.xlabel(' number of elements in an array')
    case 120:
        plt.scatter(X[:27], Y[:27],color='b')
        plt.title('Graph t(N) for bin search on worst')
        plt.ylabel('time, nanoseconds')
        plt.xlabel('log of number of elements in an array')
    case 121:
        plt.scatter(X[:27], Y[:27],color='b')
        plt.title('Graph t(N) for bin search on avg')
        plt.ylabel('time, nanoseconds')
        plt.xlabel('log of number of elements in an array')
    case 210:
        plt.scatter(X[3:], Y[3:],color='b')
        plt.title('Graph t(N) for sum search on worst')
        plt.ylabel('log of time, nanoseconds')
        plt.xlabel(' number of elements in an array')
    case 211:
        plt.scatter(X[3:], Y[3:],color='b')
        plt.title('Graph t(N) for sum search on avg')
        plt.ylabel('log of time, nanoseconds')
        plt.xlabel(' number of elements in an array')
    case 220:
        plt.scatter(X[1:100], Y[1:100],color='b')
        plt.title('Graph t(N) for smartsum search on worst')
        plt.ylabel('time, nanoseconds')
        plt.xlabel(' number of elements in an array')
    case 221:
        plt.scatter(X[8:100], Y[8:100],color='b')
        plt.title('Graph t(N) for smartsum search on avg')
        plt.ylabel('time, nanoseconds')
        plt.xlabel(' number of elements in an array')
    case 310: 
        plt.scatter(X[0:100], Y[0:100],color='b')
        plt.scatter(X[101:200], Y[101:200],color='r')
        plt.scatter(X[201:300], Y[201:300],color='g')
        plt.scatter(X[301:400], Y[301:400],color='k')
        plt.title('Graph t(N) for lin search on random')
        plt.ylabel('time, nanoseconds')
        plt.xlabel('number of elements in an array')
        plt.legend(["default", "str 1","str 2", "str 3"])
    case 311: 
        plt.scatter(X[0:100], Y[0:100],color='b')
        plt.scatter(X[101:200], Y[101:200],color='r')
        plt.scatter(X[201:300], Y[201:300],color='g')
        plt.scatter(X[301:400], Y[301:400],color='k')
        plt.title('Graph t(N) for lin search on chosen')
        plt.ylabel('time, nanoseconds')
        plt.xlabel('number of elements in an array')
        plt.legend(["default", "str 1","str 2", "str 3"])
    case 320: 
        plt.scatter(X[:27], Y[:27],color='b')
        plt.scatter(X[28:54], Y[28:54],color='r')
        plt.scatter(X[55:81], Y[55:81],color='g')
        plt.scatter(X[82:108], Y[82:108],color='k')
        plt.title('Graph t(N) for bin search on random')
        plt.ylabel('time, nanoseconds')
        plt.xlabel('log of number of elements in an array')
        plt.legend(["default", "str 1","str 2", "str 3"])
    case 321: 
        plt.scatter(X[:27], Y[:27],color='b')
        plt.scatter(X[28:54], Y[28:54],color='r')
        plt.scatter(X[55:81], Y[55:81],color='g')
        plt.scatter(X[82:108], Y[82:108],color='k')
        plt.title('Graph t(N) for bin search on chosen')
        plt.ylabel('time, nanoseconds')
        plt.xlabel('log of number of elements in an array')
        plt.legend(["default", "str 1","str 2", "str 3"])
plt.show()