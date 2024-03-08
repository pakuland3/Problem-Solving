#include <bits/stdc++.h>
#define MOD 10007
using namespace std;

int dp[1001][1001]={0,};
int n,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
    cout << dp[n][k];
    return 0;
}