#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bitset<(int)(1e5+1)> vis;
vector<vector<int>> graph;
vector<int> dp;

int solve(int a){
    vis[a]=1;
    if(graph[a].size()==0){
        return dp[a];
    }
    int t=0;
    for(int i=0;i<graph[a].size();i++){
        if(!vis[graph[a][i]]) t+=solve(graph[a][i]);
    }
    return dp[a]+=t;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,r,qq;
    cin >> n >> r >> qq;
    graph.resize(n+1);
    dp.resize(n+1,1);
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vis[r]=1;
    solve(r);
    while(qq--){
        int a;
        cin >> a;
        cout << dp[a] << '\n';
    }
    return 0;
}