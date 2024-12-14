import sys
input = lambda: sys.stdin.readline().rstrip('\n')
nums=[
    ["***","* *","* *","* *","***"],
    ["  *","  *","  *","  *","  *"],
    ["***","  *","***","*  ","***"],
    ["***","  *","***","  *","***"],
    ["* *","* *","***","  *","  *"],
    ["***","*  ","***","  *","***"],
    ["***","*  ","***","* *","***"],
    ["***","  *","  *","  *","  *"],
    ["***","* *","***","* *","***"],
    ["***","* *","***","  *","***"]
]
a=[[] for _ in range(8)]
n=[]
for _ in range(5):
    s=input()
    for j in range(0,len(s),4):
        a[j//4].append(s[j:j+3])
for l in a:
    if not len(l):
        break
    isnum=False
    for i in range(10):
        diff=False
        for j in range(5):
            if l[j]!=nums[i][j]:
                diff=True
                break
        if not diff:
            n.append(i)
            isnum=True
    if not isnum:
        print("BOOM!!")
        exit(0)
n.reverse()
res=0
for i in range(len(n)):
    res+=pow(10,i)*n[i]
if res%6==0:
    print("BEER!!")
else:
    print("BOOM!!")