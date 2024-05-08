#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
vector<vector<int>> c(3);

int getMinimumAnswer(int s){
    vector<vector<int>> dp(n, vector<int> (3,2000));
    dp[0][s]=c[s][0];
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+c[0][i];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+c[1][i];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+c[2][i];
    }
    int ans=1e6;
    for(int i=0;i<3;i++) if(i!=s) ans=min(ans,dp[n-1][i]);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    c[0].resize(n);
    c[1].resize(n);
    c[2].resize(n);
    for(int i=0;i<n;i++) cin >> c[0][i] >> c[1][i] >> c[2][i];
    cout << min(min(getMinimumAnswer(0),getMinimumAnswer(1)),getMinimumAnswer(2));
    return 0;
}