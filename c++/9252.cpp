#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string a,b;
vector<vector<pair<int,int>>> dp(1001,vector<pair<int,int>> (1001,{0,0}));

void solve(int i, int j){
    if(i==0 || j==0) return;
    if(dp[i][j].second==2){solve(i-1,j-1); cout << a[i-1];}
    if(dp[i][j].second==0) solve(i-1,j);
    if(dp[i][j].second==1) solve(i,j-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    for(int i=1;i<=a.length();i++) for(int j=1;j<=b.length();j++){
        if(dp[i-1][j].first>dp[i][j-1].first){
            dp[i][j].first=dp[i-1][j].first;
            dp[i][j].second=0;
        }
        else{
            dp[i][j].first=dp[i][j-1].first;
            dp[i][j].second=1;
        }
        if(a[i-1]==b[j-1] && dp[i][j].first<dp[i-1][j-1].first+1){
            dp[i][j].first=dp[i-1][j-1].first+1;
            dp[i][j].second=2;
        }
    }
    cout << dp[a.length()][b.length()].first << '\n';
    solve(a.length(),b.length());
    return 0;
}