#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> g[1001];
int c[1001];
int vis[1001];

int dfs(int x){
    if(vis[x]) return 0;
    vis[x]=1;
    int s=x;
    for(int nx:g[x]){
        if(s!=x) g[s].push_back(nx);
        s=dfs(nx);
    }
    while(g[x].size()>1) g[x].pop_back();
    return s;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        int C;
        cin >> C;
        while(C--){
            int a;
            cin >> a;
            g[i].push_back(a);
            c[a]++;
        }
    }
    int s;
    for(int i=1;i<=n;i++) if(!c[i]) s=i;
    dfs(s);
    cout << "1\n0\n";
    for(int i=1;i<=n;i++){
        cout << g[i].size() << ' ';
        for(int x:g[i]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}