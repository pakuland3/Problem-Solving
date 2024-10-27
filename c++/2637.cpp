#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
using namespace std;

int n,m;
int req[100][100];
int cnt[100];
bool unit[100];
vector<vector<pair<int,int>>> graph;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    graph.resize(n);
    while(m--){
        int x,y,k;
        cin >> x >> y >> k;
        graph[--y].push_back({--x,k});
        cnt[x]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++) if(cnt[i]==0){ q.push(i); unit[i]=1; }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(cnt[now]==0) req[now][now]=1;
        for(int i=0;i<graph[now].size();i++){
            pii p=graph[now][i];
            for(int j=0;j<n;j++) req[p.fi][j]+=p.se*req[now][j];
            cnt[p.fi]--;
            if(cnt[p.fi]==0) q.push(p.fi);
        }
    }
    for(int i=0;i<n;i++) if(unit[i]) cout << i+1 << ' ' << req[n-1][i] << '\n';
    return 0;
}