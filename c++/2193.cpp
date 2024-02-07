#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
ll dp[91][2];

int main(){
    dp[0][0]=0;
    dp[0][1]=1;
    cin >> n;
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout << dp[n-1][0]+dp[n-1][1];
    return 0;
}