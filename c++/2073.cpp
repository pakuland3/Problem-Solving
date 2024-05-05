#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int d,p;
    cin >> d >> p;
    vector<int> l(p),c(p);
    vector<vector<int>> dp(2,vector<int> (d+1,0));
    for(int i=0;i<p;i++) cin >> l[i] >> c[i];
    dp[0][l[0]]=c[0];
    for(int i=1;i<p;i++) for(int j=1;j<=d;j++){
        dp[i%2][j]=dp[!(i%2)][j];
        if(j<l[i]) continue;
        if(j!=l[i] && dp[!(i%2)][j-l[i]]==0) continue;
        if(j==l[i]) dp[i%2][j]=max(dp[!(i%2)][j],c[i]);
        else dp[i%2][j]=max(dp[!(i%2)][j],min(dp[!(i%2)][j-l[i]],c[i]));
    }
    cout << dp[!(p%2)][d];
    return 0;
}