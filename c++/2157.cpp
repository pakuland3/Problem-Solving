#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(m,vector<int> (n,-1)),cost(n,vector<int> (n,-1));
    for(int i=0;i<k;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a>b) continue;
        cost[a][b]=max(cost[(--a)][(--b)],c);
    }
    dp[0][0]=0;
    for(int i=1;i<m;i++) for(int j=0;j<n;j++) for(int k=0;k<j;k++){
        if(cost[k][j]!=-1 && dp[i-1][k]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][k]+cost[k][j]);
    }
    int ans=0;
    for(int i=1;i<m;i++) ans=max(ans,dp[i][n-1]);
    cout << ans;
    return 0;
}