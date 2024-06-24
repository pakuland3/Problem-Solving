#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int i, int j, bool k,vector<vector<int>> &dp, vector<int> &a){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(k) return dp[i][j]=max(solve(i,j-1,0,dp,a)+a[j],solve(i+1,j,0,dp,a)+a[i]);
    return dp[i][j]=min(solve(i,j-1,1,dp,a),solve(i+1,j,1,dp,a));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        vector<int> a(n);
        for(int &s:a) cin >> s;
        cout << solve(0,n-1,1,dp,a) << '\n';
    }
    return 0;
}