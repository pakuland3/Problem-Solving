#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,t,ans=0;
    cin >> n >> t;
    vector<int> k(n),s(n);
    vector<vector<int>> dp(n+1,vector<int> (t+1,0));
    for(int i=0;i<n;i++) cin >> k[i] >> s[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            int cnt=min(1,j/k[i-1]);
            dp[i][j]=(cnt>0)?max(dp[i-1][j],dp[i-1][j-k[i-1]]+s[i-1]):dp[i-1][j];
        }
    }
    for(int i=1;i<=t;i++) ans=max(ans,dp[n][i]);
    cout << ans;
    return 0;
}