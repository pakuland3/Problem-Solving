#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool vis[100001];
bool f_wins[100001];
vector<vector<int>> graph;

void solve(int s, int e, int node, bool turn){
    if(node==e || (graph[node].size()==1 && node!=s)) return;
    int cnt=0;
    for(int i=0;i<graph[node].size();i++){
        int nx=graph[node][i];
        if(vis[nx]) continue;
        vis[nx]=1;
        solve(s,e,nx,!turn);
        if(f_wins[nx]) f_wins[node]=1;
        else cnt++;
    }
    if(f_wins[node] && cnt>0 && turn) f_wins[node]=0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,s,e;
    cin >> n >> s >> e;
    graph.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vis[s]=1;
    f_wins[e]=1;
    solve(s,e,s,0);
    cout << (f_wins[s]?"First":"Second");
    return 0;
}