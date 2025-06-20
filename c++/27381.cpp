#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> ord[2];
vector<int> g[200001];
int cnt[200001];
int vis[200001];

void dfs(int now, int c){
    if(vis[now]) return;
    ord[c].push_back(now);
    vis[now]=1;
    for(int nx:g[now]) dfs(nx,!c);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        ord[0].clear();
        ord[1].clear();
        for(int i=1;i<=n;i++) g[i].clear();
        memset(vis,0,4*n+4);
        memset(cnt,0,4*n+4);
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            cnt[a]++;
            cnt[b]++;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        if(n==2 || n==3){
            cout << "-1\n";
            continue;
        }
        int s;
        int c=0;
        for(int i=1;i<=n;i++) if(cnt[i]==1){
            s=i;
            c++;
        }
        if(c==n-1){
            cout << "-1\n";
            continue;
        }
        dfs(s,0);
        for(int x:ord[1]) cout << x << ' ';
        for(int x:ord[0]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}