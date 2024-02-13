#include <bits/stdc++.h>
using namespace std;

int n;
int dp[100001];

int main(){
    cin >> n;
    fill(dp,dp+n+1,100000);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sqrt(i);j++) dp[i]=min(dp[i],dp[i-j*j]+1);
    }
    cout << dp[n];
}