#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int vis[100001];
int scc[100001];
vector<int> g[100001],gr[100001],order;

void dfs(int now){
    if(vis[now]) return;
    vis[now]=1;
    for(int nx:g[now]) dfs(nx);
    order.push_back(now);
}

void dfs_rev(int now, int num){
    if(vis[now]) return;
    vis[now]=1;
    scc[now]=num;
    for(int nx:gr[now]) dfs_rev(nx,num);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        memset(vis,0,sizeof(vis));
        order.clear();
        for(int i=0;i<100000;i++){
            g[i].clear();
            gr[i].clear();
        }
        int n,m;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            gr[b].push_back(a);
        }
        for(int i=0;i<n;i++) dfs(i);
        memset(vis,0,sizeof(vis));
        reverse(order.begin(),order.end());
        int cnt=0;
        for(int i:order) if(!vis[i]) dfs_rev(i,++cnt);
        memset(vis,0,sizeof(vis));
        dfs(order[0]);
        auto solve=[&]() -> int {
            for(int i=1;i<n;i++) if(!vis[order[i]]) return 0;
            return 1;
        };
        if(solve()){
            for(int i=0;i<n;i++){
                if(scc[i]==1) cout << i << '\n';
            }
        }
        else cout << "Confused\n";
        cout << '\n';
    }
    return 0;
}