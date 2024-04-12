#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
ll dp[16];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dp[0]=1;
    dp[1]=3;
    dp[2]=11;
    cin >> n;
    if(n%2!=0){cout << 0; return 0;}
    for(int i=3;i<=n/2;i++){
        dp[i]=dp[i-1]*3;
        for(int j=2;j<=i;j++) dp[i]+=dp[i-j]*2;
    }
    cout << dp[n/2];
    return 0;
}