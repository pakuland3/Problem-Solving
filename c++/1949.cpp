#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> dp,graph;
int a[10001];
bool vis[10001];

void solve(int node){
    bool isLeaf=1;
    dp[node][0]=0;
    dp[node][1]=a[node];
    for(int i=0;i<graph[node].size();i++){
        int nx=graph[node][i];
        if(vis[nx]) continue;
        isLeaf=0;
        vis[nx]=1;
        solve(nx);
        dp[node][1]+=dp[nx][0];
        dp[node][0]+=max(dp[nx][1],dp[nx][0]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    graph.resize(n+1);
    dp.resize(n+1,vector<int>(2,-1));
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int b,c;
        cin >> b >> c;
        graph[b].push_back(c);
        graph[c].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(graph[i].size()==1){
            vis[i]=1;
            solve(i);
            cout << max(dp[i][0],dp[i][1]);
            return 0;
        }
    }
    return 0;
}