#include <bits/stdc++.h>
#define INF INT32_MAX
#define FI first
#define SE second
typedef long long ll;
using namespace std;

int n,s,e,m;
vector<pair<int,ll>> graph[50];
ll earn[50];
ll d[50];
queue<int> q;
bool vis[50];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> s >> e >> m;
    fill(d,d+50,INF);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    for(int i=0;i<n;i++) cin >> earn[i];
    d[s]=-earn[s];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<graph[j].size();k++){
                int a=j;
                int b=graph[j][k].FI;
                ll c=graph[j][k].SE;
                if(d[a]!=INF && d[a]+c-earn[b]<d[b]){
                    if(i==n-1){
                        q.push(b);
                        vis[b]=1;
                    }
                    d[b]=d[a]+c-earn[b];
                }
            }
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            int nx=graph[x][i].FI;
            if(vis[nx]) continue;
            vis[nx]=1;
            q.push(nx);
        }
    }
    if(vis[e]) cout << "Gee";
    else if(d[e]==INF) cout << "gg";
    else cout << -d[e];
    return 0;
}