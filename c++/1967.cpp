#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

vector<vector<pair<int,int>>> graph;
pair<int,int> maxi={1,0};
int n;

void solve(int start){
    vector<bool> vis(n+1,0);
    queue<pair<int,int>> q;
    vis[start]=1;
    q.push({start,0});
    while(!q.empty()){
        int now=q.front().fi;
        int cost=q.front().se;
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            int nx=graph[now][i].fi;
            if(vis[nx]) continue;
            vis[nx]=1;
            if(maxi.se<cost+graph[now][i].se) maxi={nx,cost+graph[now][i].se};
            q.push({nx,cost+graph[now][i].se});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    graph.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    solve(1);
    solve(maxi.fi);
    cout << maxi.se;
    return 0;
}