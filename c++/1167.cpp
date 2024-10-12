#include <bits/stdc++.h>
#define FI first
#define SE second
typedef long long ll;
using namespace std;

vector<vector<pair<int,ll>>> graph;
queue<pair<int,ll>> q;
bool vis[100001];
int cnt[100001];
ll res=0;

void bfs(int a){
    q.push({a,0});
    while(!q.empty()){
        vis[q.front().FI]=1;
        ll cur=q.front().SE;
        res=max(res,cur);
        int a=q.front().FI;
        q.pop();
        for(int i=0;i<graph[a].size();i++){
            int na=graph[a][i].FI;
            if(vis[na]) continue;
            if(cnt[na]==1 && cur<graph[a][i].SE){
                res=max(res,cur+graph[a][i].SE);
                cur=0;
                vis[a]=0;
                q.push({na,0});
            }
            else q.push({na,cur+graph[a][i].SE});
        }
    }
}

void dfs(int a, ll cur){
    vis[a]=1;
    res=max(res,cur);
    for(int i=0;i<graph[a].size();i++){
        int na=graph[a][i].FI;
        if(vis[na]) continue;
        if(cnt[na]==1 && cur<graph[a][i].SE){
            res=max(res,cur+graph[a][i].SE);
            vis[a]=0;
            dfs(na,0);
        }
        else dfs(na,cur+graph[a][i].SE);
    }
    vis[a]=0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("input","r",stdin);
    int n;
    cin >> n;
    graph.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> i;
        int to;
        while((cin >> to) && to!=-1){
            cnt[to]++;
            int c;
            cin >> c;
            graph[i].push_back({to,c});
        }
    }
    for(int i=1;i<=n;i++) 
        if(cnt[i]==1){
            dfs(i,0);
            break;
        }
    cout << res;
    return 0;
}