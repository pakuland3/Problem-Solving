#include <bits/stdc++.h>
#define FI first
#define SE second
typedef long long ll;
using namespace std;

int d[100001],c[100001];
bool vis[100001];

vector<vector<pair<int,int>>> graph;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v;
    cin >> v;
    graph.resize(v+1);
    int to,cost;
    for(int i=0;i<v;i++){
        int start;
        cin >> start;
        while(1){
            cin >> to;
            if(to==-1) break;
            cin >> cost;
            c[to]++;
            c[start]++;
            graph[start].push_back({to,cost});
        }
    }
    queue<int> q;
    for(int i=1;i<=v;i++){
        if(c[i]==2){
            q.push(i);
            vis[i]=1;
            d[i]=0;
            break;
        }
    }
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int i=0;i<graph[a].size();i++){
            int na=graph[a][i].FI;
            if(vis[na]) continue;
            vis[na]=1;
            d[na]=d[a]+graph[a][i].SE;
            q.push(na);
        }
    }
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=v;i++) pq.push({d[i],i});
    pair<int,int> a=pq.top();
    memset(vis,0,sizeof(vis));
    q.push(a.SE);
    d[a.SE]=0;
    vis[a.SE]=1;
    while(!q.empty()){
        int aa=q.front();
        q.pop();
        for(int i=0;i<graph[aa].size();i++){
            int na=graph[aa][i].FI;
            if(vis[na]) continue;
            vis[na]=1;
            d[na]=d[aa]+graph[aa][i].SE;
            q.push(na);
        }
    }
    for(int i=1;i<=v;i++) pq.push({d[i],i});
    cout << pq.top().FI;
    return 0;
}