#include <bits/stdc++.h>
#define M INT64_MAX
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        ll a,b;
        cin >> n >> k >> a >> b;
        vector<pair<ll, ll>> l(n);
        for(pair<ll, ll> &p:l){
            cin >> p.first;
            if(p.first!=1) p.second=a*(p.first-1)*(p.first-1)+b;
            else p.second=0;
        }
        vector<vector<ll>> dp(2,vector<ll> (1e4+101,M));
        dp[0][0]=dp[1][0]=0;
        for(int i=0;i<n;i++) for(int j=1;j<=1e4+100;j++){
            if(dp[!(i%2)][j]!=M) dp[i%2][j]=dp[!(i%2)][j];
            if(j>=l[i].first && dp[!(i%2)][j-l[i].first]!=M) dp[i%2][j]=min(dp[i%2][j],dp[!(i%2)][j-l[i].first]+l[i].second);
        }
        ll ans=dp[(n-1)%2][k];
        for(int i=k+1;i<=1e4+100;i++) ans=min(ans,dp[(n-1)%2][i]);
        cout << ans << '\n';
    }
    return 0;
}