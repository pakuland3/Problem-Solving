#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,ans=0;
    cin >> n >> m;
    vector<int> a(m+1),b(m+1),c(m+1),d(m+1);
    cin >> c[0] >> d[0];
    for(int i=1;i<=m;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<vector<int>> dp(m+2,vector<int> (n+1,0));
    for(int i=1;i<m+2;i++){
        for(int j=1;j<=n;j++){
            int cnt=(i!=1)?min(a[i-1]/b[i-1],j/c[i-1]):j/c[0];
            dp[i][j]=(cnt>0)?max(dp[i-1][j],dp[i-1][j-cnt*c[i-1]]+cnt*d[i-1]):dp[i-1][j];
        }
    }
    for(int i=1;i<=n;i++) ans=max(ans,dp[m+1][i]);
    cout << ans;
    return 0;
}