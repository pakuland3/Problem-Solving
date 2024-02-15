#include <bits/stdc++.h>
#define INF 1e11
typedef long long ll;
using namespace std;

int n,m; //worst cost will be 10^10
int s,e;
ll d[1001];
vector<pair<int, int>> graph[1001];

void dijkstra(){
    priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        ll dist=pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(d[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            ll cost=dist+graph[now][i].second;
            if(cost<d[graph[now][i].first]){
                d[graph[now][i].first]=cost;
                pq.push({cost,graph[now][i].first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fill(d,d+n+1,INF);
    for(int i=0;i<m;i++){
        int a;int b;int c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    cin >> s >> e;
    dijkstra();
    cout << d[e];
}