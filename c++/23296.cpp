#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int ind[100001];
int adj[100001];
int vis[100001];
vector<int> ans;
queue<int> q;

void bfs(int s){
    q.push(s);
    vis[s]=1;
    while(q.size()){
        int now=q.front();
        q.pop();
        int nx=adj[now];
        ans.push_back(nx);
        if(vis[nx]) continue;
        vis[nx]=1;
        q.push(nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> adj[i];
        ind[adj[i]]++;
    }
    bfs(1);
    for(int i=2;i<=n;i++){
        if(!ind[i]){
            ans.push_back(i);
            bfs(i);
        }
    }
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            ans.push_back(i);
            bfs(i);
        }
    }
    cout << ans.size() << '\n';
    for(int t:ans) cout << t << ' ';
    return 0;
}