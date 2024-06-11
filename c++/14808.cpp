#include <bits/stdc++.h>
#define INF (ll)2e11
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(7);
    cout << fixed;
    int t;
    cin >> t;
    for(int p=1;p<=t;p++){
        int n,q;
        cin >> n >> q;
        vector<double> E(n),S(n);
        vector<vector<double>> dp(n,vector<double> (n));
        vector<vector<ll>>  d(n,vector<ll> (n));
        for(int i=0;i<n;i++) cin >> E[i] >> S[i];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            cin >> d[i][j];
            if(d[i][j]==-1) d[i][j]=INF;
        }
        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(E[i]<d[i][j]) dp[i][j]=INF;
            else dp[i][j]=d[i][j]/S[i];
        }
        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        cout << "Case #" << p << ": ";
        for(int i=0;i<q;i++){
            int u,v;
            cin >> u >> v;
            cout << dp[u-1][v-1] << ' ';
        }
        cout << '\n';
    }
    return 0;
}