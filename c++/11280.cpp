#include <bits/stdc++.h>
#define SIZE 20001
typedef long long ll;
using namespace std;

int vis[SIZE];
int scc[SIZE];
vector<int> order;
vector<int> g[SIZE];
vector<int> gr[SIZE];

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
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(a<0) a=-a+n;
        if(b<0) b=-b+n;
        int na=(a>n?a-n:a+n),nb=(b>n?b-n:b+n);
        g[na].push_back(b);
        g[nb].push_back(a);
        gr[b].push_back(na);
        gr[a].push_back(nb);
    }
    for(int i=1;i<=2*n;i++) dfs(i);
    reverse(order.begin(),order.end());
    memset(vis,0,sizeof(vis));
    int cnt=0;
    for(int i:order){
        if(!vis[i]){
            dfs_rev(i,++cnt);
        }
    }
    for(int i=1;i<=n;i++){
        if(scc[i]==scc[i+n]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}