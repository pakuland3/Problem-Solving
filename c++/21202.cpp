#include <bits/stdc++.h>
using namespace std;

vector<int> g[200000];
int w[200000];
int vis[200000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++) cin >> w[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int res=0;
    pq.push({w[0],0});
    while(!pq.empty()){
        int now=pq.top().second;
        pq.pop();
        if(now!=0 && w[now]>=res) break;
        if(vis[now]) continue;
        res+=w[now];
        vis[now]=1;
        for(int i=0;i<g[now].size();i++) pq.push({w[g[now][i]],g[now][i]});
    }
    cout << res;
    return 0;
}