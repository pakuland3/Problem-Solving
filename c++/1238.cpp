#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<pair<int, int>>> graph;
int n,m,x,ans=0;

int dijkstra(int a, int b){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(n+1,1e9);
    pq.push({0,a});
    d[a]=0;
    while(!pq.empty()){
        int now=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        for(int i=0;i<graph[now].size();i++){
            int cost=dist+graph[now][i].second;
            if(d[graph[now][i].first]>cost){
                d[graph[now][i].first]=cost;
                pq.push({cost,graph[now][i].first});
            }
        }
    }
    return d[b];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++) ans=max(ans,dijkstra(i,x)+dijkstra(x,i));
    cout << ans;
    return 0;
}