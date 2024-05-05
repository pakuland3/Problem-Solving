#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans=0;
    cin >> n;
    vector<int> l(n),j(n);
    vector<vector<int>> dp(n+1,vector<int> (100,0));
    for(int &a:l) cin >> a;
    for(int &a:j) cin >> a;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=99;k++){
            int cnt=(l[i-1]!=0)?min(1,k/l[i-1]):1;
            dp[i][k]=(cnt>0)?max(dp[i-1][k],dp[i-1][k-l[i-1]]+j[i-1]):dp[i-1][k];
        }
    }
    for(int i=0;i<100;i++) ans=max(ans,dp[n][i]);
    cout << ans;
    return 0;
}