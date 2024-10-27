#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int &t:a) cin >> t;
    for(int &t:b) cin >> t;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j) dp[i][j]=dp[i-1][j-1]+abs(a[i-1]-b[j-1]);
            if(i>j) dp[i][j]=min(dp[i-1][j-1]+abs(a[i-1]-b[j-1]),dp[i-1][j]);
            if(i<j) dp[i][j]=min(dp[i-1][j-1]+abs(a[i-1]-b[j-1]),dp[i][j-1]);
        }
    }
    cout << dp[n][m];
    return 0;
}