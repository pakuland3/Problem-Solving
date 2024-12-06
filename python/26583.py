import sys
input = lambda: sys.stdin.readline().rstrip()
while 1:
    s=input()
    if s=="":
        break
    a=list(map(int,s.split()))
    b=a[:]
    for i in range(len(a)):
        if i!=0:
            b[i-1]*=a[i]
        if i!=len(a)-1:
            b[i+1]*=a[i]
    for t in b:
        print(t,end=' ')
    print("")