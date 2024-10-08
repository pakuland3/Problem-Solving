n=int(input())
a=[]
for _ in range(n):
    b=input()
    a.append(b)
k=int(input())
h=[[0,0] for _ in range(36)]
for i in range(36): h[i][0]=i
for s in a:
    for idx,c in enumerate(s):
        t=ord(c)
        if ord('A')<=t and t<=ord('Z'): h[10+t-ord('A')][1]+=pow(36,len(s)-idx-1)
        else: h[t-ord('0')][1]+=pow(36,len(s)-idx-1)

# let chosen number l
# change l to z is adding (z-l)*h[l-'A']
h.sort(key=lambda x:(35-x[0])*x[1])

sum=0
for i in range(k): sum+=35*h[35-i][1]
for i in range(36-k): sum+=h[i][0]*h[i][1]

res=""
while(sum>0):
    sum,mod=divmod(sum,36)
    if 9<mod and mod<36: res+=chr(55+mod)
    else: res+=str(mod)

res=res[::-1]

if res!="": print(res)
else: print(0)