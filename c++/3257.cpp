#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a,b,c;
    cin >> a >> b >> c;
    int la=a.length(),lb=b.length(),cnt=c.length();
    vector<vector<int>> dp(la+1,vector<int> (lb+1,0));
    vector<int> ans(cnt,0);
    dp[0][0]=1;
    for(int i=0;i<=la;i++) for(int j=0;j<=lb;j++){
        if(i && dp[i-1][j] && c[i+j-1]==a[i-1]) dp[i][j]=1;
        if(j && dp[i][j-1] && c[i+j-1]==b[j-1]) dp[i][j]=2;
    }
    for(int i=0;i<cnt;i++){
        ans[cnt-(i+1)]=dp[la][lb];
        if(dp[la][lb]==1) la--;
        else lb--;
    }
    for(int &t:ans) cout << t;
    return 0;
}