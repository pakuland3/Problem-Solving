n=int(input())
a=list(input().split(' '))
for s in a:
    if len(s)%2:
        s=s[:-1]
    for i in range(1,len(s),2):
        x=ord(s[i-1])+ord(s[i])-2*ord('a')-n+26
        print(chr(x%26+ord('a')),end='')
    print("",end=' ')