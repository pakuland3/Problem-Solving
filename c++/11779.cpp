#include <bits/stdc++.h>
#define INF 1e12
typedef long long ll;
using namespace std;

int n,m;
ll d[1001];
int cnt[1001];
int s,e;
vector<pair<int, int>> rev[1001];
vector<pair<int, int>> graph[1001];

void dijkstra(){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0,s}); d[s]=0; cnt[s]=1;
    while(!pq.empty()){
        int now=pq.top().second;
        ll dist=pq.top().first;
        pq.pop();
        if(d[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            ll cost=dist+graph[now][i].second;
            if(d[graph[now][i].first]>cost){
                d[graph[now][i].first]=cost;
                rev[graph[now][i].first].push_back({now, cost});
                cnt[graph[now][i].first]=cnt[now]+1;
                pq.push({cost,graph[now][i].first});
            }
        }
    }
    queue<int> q;
    vector<int> ans;
    ans.push_back(e);
    q.push(e);
    while(!q.empty()){
        int now=q.front();
        q.pop();            //처리 부분에서 rev 활용 말고, 최단 경로인지만 확인하는 pair 사용해서 해야할듯
        for(int i=rev[now].size()-1;i>-1;i--){ //ex) {노드번호, 경로}
            
        }
    }
    cout << d[e] << '\n' << ans.size() << '\n';
    for(int i=ans.size()-1;i>-1;i--) cout << ans[i] << ' ';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m; fill(d,d+n+1,INF);
    for(int i=0;i<m;i++){
        int a;int b;int c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    cin >> s >> e;
    dijkstra();
}