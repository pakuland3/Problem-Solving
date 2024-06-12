#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<ll>> dp(n,vector<ll> (n,(ll)INT64_MAX));
        for(int i=0;i<n;i++) dp[i][i]=0;
        cin >> a[0];
        for(int i=1;i<n;i++){
            cin >> a[i];
            a[i]+=a[i-1];
        }
        for(int i=1;i<n;i++) for(int j=0;i+j<n;j++) for(int k=j;k<i+j;k++) dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+a[k]+a[i+j]-a[k]-(j!=0?a[j-1]:0));
        cout << dp[0][n-1] << '\n';
    }
    return 0;
}