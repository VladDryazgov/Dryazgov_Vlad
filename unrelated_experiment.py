def f(x,y):
    a=x
    for i in range (y-1):
        a=a**x
        i+=1
    return a
for i in range(1,8):
    print(f(6,i)%15)