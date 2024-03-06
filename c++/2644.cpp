#include <bits/stdc++.h>
using namespace std;

vector<int> arr[101];
int d[101]={0,};
int n,s,e,m;
bool vis[101]={0,};

void bfs(int start){
    d[start]=0;
    vis[start]=true;
    queue<int> q; q.push(start);
    while(!q.empty()){
        int now=q.front(); q.pop();
        for(int next:arr[now]){
            if(vis[next]) continue;
            d[next]=d[now]+1;
            vis[next]=true;
            q.push(next);
        }
    }
    if(d[e]==0) cout << -1;
    else cout << d[e];
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s >> e >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        arr[a].push_back(b); arr[b].push_back(a);
    }
    bfs(s);
    return 0;
}