#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> dp,graph;
bool vis[1000001];

void solve(int node){
    dp[node][1]=1;
    for(int i=0;i<graph[node].size();i++){
        int nx=graph[node][i];
        if(vis[nx]) continue;
        vis[nx]=1;
        solve(nx);
        dp[node][1]+=min(dp[nx][0],dp[nx][1]);
        dp[node][0]+=dp[nx][1];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    graph.resize(n+1);
    dp.resize(n+1,vector<int>(2,0));
    for(int i=1;i<n;i++){
        int b,c;
        cin >> b >> c;
        graph[b].push_back(c);
        graph[c].push_back(b);
    }
    vis[1]=1;
    solve(1);
    cout << min(dp[1][1],dp[1][0]);
    return 0;
}