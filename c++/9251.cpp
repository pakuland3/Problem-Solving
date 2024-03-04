#include <bits/stdc++.h>
using namespace std;

string a,b;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<a.length();i++) for(int j=0;j<b.length();j++){
        if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
        else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
    }
    cout << dp[a.length()][b.length()];
    return 0;
}