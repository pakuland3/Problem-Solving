import decimal

decimal.getcontext().prec=1200

def solve(a, b):
    if b==1:
        return a
    c=solve(a,b//2)
    c*=c
    if b%2==1: c*=a
    return c

a,b=input().split()

b=int(b)

a=decimal.Decimal(a)

print("{0:f}".format(solve(a,b)))