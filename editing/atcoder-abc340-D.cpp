#include <bits/stdc++.h>
#define INF 1e15
typedef long long ll;
using namespace std;

int n;
vector<pair<int, int>> graph[200001];
int a,b,x;
ll d[200001];

void dijkstra(){
    priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    d[1]=0;
    pq.push({0,1});
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
    cout << d[n];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fill(d,d+n+1,INF);
    for(int i=1;i<n;i++){
        cin >> a >> b >> x;
        graph[i].push_back({i+1,a});
        graph[i].push_back({x,b});
    }
    dijkstra();
}