#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

void solve(){
    int n,m,t,s,g,h,a,b,dis;
    cin >> n >> m >> t >> s >> g >> h;
    vector<vector<pair<int, int>>> graph(n+1);
    vector<int> des(t),d(n+1,INF);
    vector<bool> ck(n+1,0);
    for(int i=0;i<m;i++){
        cin >> a >> b >> dis;
        graph[a].push_back({b,dis});
        graph[b].push_back({a,dis});
    }
    for(int i=0;i<t;i++) cin >> des[i];
    sort(des.begin(),des.end());
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[s]=0; pq.push({0,s});
    while(!pq.empty()){
        int now=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        for(int i=0;i<graph[now].size();i++){
            int cost=dist+graph[now][i].second;
            if(d[graph[now][i].first]>=cost){
                if(now==g && graph[now][i].first==h) ck[h]=1;
                else if(now==h && graph[now][i].first==g) ck[g]=1;
                else if(ck[now]) ck[graph[now][i].first]=1;
                else if(d[graph[now][i].first]>cost) ck[graph[now][i].first]=0;
                if(d[graph[now][i].first]>cost){
                    d[graph[now][i].first]=cost;
                    pq.push({cost,graph[now][i].first});
                }
            }
        }
    }
    for(int i=0;i<t;i++) if(ck[des[i]]) cout << des[i] << ' ';
    cout << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}