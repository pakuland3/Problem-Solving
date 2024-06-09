#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct matrix{
    int r,c;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<matrix> a(n);
    for(auto &t:a) cin >> t.r >> t.c;
    vector<vector<ll>> dp(n,vector<ll> (n,INT32_MAX));
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i=1;i<=n-1;i++) 
		for(int j=0;i+j<n;j++) 
			for(int k=j;k<i+j;k++) 
				dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+a[j].r*a[k].c*a[i+j].c);
	cout << dp[0][n-1];
    return 0;
}