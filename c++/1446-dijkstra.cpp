#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[10001];
int dp[10001];
int s,p,l;
int n,d;

void dijkstra(){
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});
    dp[0]=0;
    while(!pq.empty()){
        int dist=pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(dp[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost=dist+graph[now][i].second;
            if(cost<dp[graph[now][i].first]){
                dp[graph[now][i].first]=cost;
                pq.push({cost,graph[now][i].first});
            }
        }
    }
    cout << dp[d];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d;
    fill(dp,dp+d+1,INF);
    for(int i=0;i<n;i++){cin >> s >> p >> l; graph[s].push_back({p,l});}
    for(int i=0;i<d;i++) graph[i].push_back({i+1,1});
    dijkstra();
}
