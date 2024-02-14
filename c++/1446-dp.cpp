#include <bits/stdc++.h>
using namespace std;

int n,d;
int dp[10001];
vector<pair<int, int>> v[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> d;
    for(int i=0;i<n;i++){int s,e,l;cin >> s >> e >> l;v[e].push_back({s,l});}
    for(int i=1;i<=d;i++){
        dp[i]=dp[i-1]+1;
        for(int j=0;j<v[i].size();j++){
            dp[i]=min(dp[i],dp[v[i][j].first]+v[i][j].second);
        }
    }
    cout << dp[d];
}