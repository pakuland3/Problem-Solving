#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int v,e,k,u,s,w;
vector<pair<int, int>> graph[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int d[20001];

void dijkstra(int start){
    pq.push({0,start});
    d[start]=0;
    while(!pq.empty()){
        int dist=pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(d[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost=dist+graph[now][i].second;
            if(cost<d[graph[now][i].first]){
                d[graph[now][i].first]=cost;
                pq.push({cost,graph[now][i].first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> v >> e >> k;
    fill(d,d+v+1,INF);
    for(int i=0;i<e;i++){cin >> u >> s >> w; graph[u].push_back({s,w});}
    dijkstra(k);
    for(int i=1;i<=v;i++){
        if(d[i]!=INF) cout << d[i] << '\n';
        else cout << "INF\n";
    }
}