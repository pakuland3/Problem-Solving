n=int(input())
dp=[[0]*2 for _ in range(1000)]
dp[1][0]=1
for i in range(2,n):
    dp[i][0]=2*dp[i-1][1]
    dp[i][1]=dp[i-1][0]+dp[i-1][1]
print(dp[n-1][0]+dp[n-1][1])