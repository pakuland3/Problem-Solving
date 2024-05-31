// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int &t:a) cin >> t;
//     vector<vector<int>> dp(n,vector<int> (n,INT32_MAX));
//     dp[0][1]=dp[1][0]=0;
//     for(int i=0;i<n-1;i++) for(int j=0;j<n-1;j++){
//         if(i==j) continue;
//         int nw=max(i,j)+1;
//         dp[nw][j]=min(dp[nw][j],dp[i][j]+abs(a[i]-a[nw]));
//         dp[i][nw]=min(dp[i][nw],dp[i][j]+abs(a[j]-a[nw]));
//     }
//     int ans=INT32_MAX;
//     for(int i=0;i<n;i++) ans=min(ans,min(dp[n-1][i],dp[i][n-1]));
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
vector<ll> a;
vector<vector<ll>> dp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    a.resize(n+1);
    dp.resize(n+1,vector<ll> (n+1,INT32_MAX));
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0][1]=dp[1][0]=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        if(i==j) continue;
        int nw=max(i,j)+1;
        if(i==0 || j==0) a[0]=a[nw];
        dp[nw][j]=min(dp[nw][j],dp[i][j]+abs(a[i]-a[nw]));
        dp[i][nw]=min(dp[i][nw],dp[i][j]+abs(a[j]-a[nw]));
    }
    ll ans=INT32_MAX;
    for(int i=0;i<n;i++) ans=min(ans,min(dp[n][i],dp[i][n]));
    cout << ans;
    return 0;
}