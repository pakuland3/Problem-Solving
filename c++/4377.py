while 1:
    try:
        dx=[-1,0,1]
        k,n=map(int,input().split())
        dp=[[0 for _ in range(k+1)] for __ in range(n)]
        for i in range(k+1): dp[0][i]=1
        for i in range(1,n):
            for j in range(k+1):
                for m in range(3):
                    l=j+dx[m]
                    if k<l or l<0: continue
                    dp[i][j]+=dp[i-1][l]
        b=0
        for i in range(k+1): b+=dp[n-1][i]
        print("{:.5f}".format(b*100/((k+1)**n)))
    except EOFError:
        break