#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool a1=true,a2=true;
int n,e,a,b,c,v1,v2;
vector<pair<int, int>> graph[801];

ll dijkstra(int s, int e){
    ll d[801];
    fill(d,d+801,1e10);
    priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int now=pq.top().second;
        ll dist=pq.top().first;
        pq.pop();
        if(dist>d[now]) continue;
        for(int i=0;i<graph[now].size();i++){
            ll cost=dist+graph[now][i].second;
            if(cost<d[graph[now][i].first]){
                d[graph[now][i].first]=cost;
                pq.push({cost,graph[now][i].first});
            }
        }
    }
    if(d[e]!=1e10) return d[e];
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    } cin >> v1 >> v2;
    ll tmp1=dijkstra(v1,v2);
    if(tmp1==-1){cout << -1; return 0;}
    ll ans1=dijkstra(1,v1);
    if(ans1==-1) a1=false;
    ans1+=tmp1;
    ll tmp2=dijkstra(v2,n);
    if(tmp2==-1) a1=false;
    ans1+=tmp2;

    ll ans2=dijkstra(1,v2);
    if(ans2==-1) a2=false;
    ans2+=tmp1;
    tmp2=dijkstra(v1,n);
    if(tmp2==-1) a2=false;
    ans2+=tmp2;
    if(!a1 && !a2){cout << -1; return 0;}
    else if(a1 && !a2) cout << ans1;
    else if(!a1 && a2) cout << ans2;
    else cout << min(ans1,ans2);
    return 0;
}