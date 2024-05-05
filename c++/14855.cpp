#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,ans=0;
    cin >> n >> m;
    vector<int> a(m+1,1),b(m+1),c(m+1),d(m+1);
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    cin >> c[0] >> d[0];
    for(int i=1;i<=m;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i=1;i<=n;i++){
        if(i%c[0]==0){dp[0][i]=i/c[0]*d[0]; ans=max(ans,dp[0][i]);}
    }
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++){
        int cnt=min(j/c[i],a[i]/b[i]);
        dp[i][j]=dp[i-1][j];
        for(int k=1;k<=cnt;k++){
            if(j!=k*c[i] && dp[i-1][j-k*c[i]]==0) continue;
            dp[i][j]=max(dp[i-1][j-k*c[i]]+k*d[i],dp[i][j]);
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}