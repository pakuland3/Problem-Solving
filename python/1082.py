n=int(input())
p=list(map(int,input().split()))
m=int(input())
dp=["" for _ in range(m+1)]

for i in range(n-1,-1,-1):
    for j in range(1,m+1):
        if dp[j]=="" and j>=p[i]:dp[j]=str(i)
        if j>=p[i] and int(dp[j])<int(dp[j-p[i]]+str(i)):dp[j]=dp[j-p[i]]+str(i)

ans=""
for i in range(m):
    if ans=="" and dp[i+1]!="": ans=dp[i+1]
    if dp[i+1]!="":ans=max(int(ans),int(dp[i+1]))
print(ans)