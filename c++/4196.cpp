#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> g[100001],gr[100001];
int vis[100001];
int num[100001];
int cnt=0;
int low[100001];
stack<int> st;
int sccs;
int n,m;
int idc[200001];
int fin[200001];

void dfs(int now){
    num[now]=++cnt;
    low[now]=cnt;
    vis[now]=1;
    st.push(now);
    for(int nx:g[now]){
        if(!num[nx]){
            dfs(nx);
            low[now]=min(low[now],low[nx]);
        }
        else if(vis[nx]) low[now]=min(low[now],num[nx]);
    }
    unordered_set<int> s;
    if(low[now]==num[now]){
        sccs++;
        while(!st.empty()){
            int t=st.top(); st.pop();
            s.insert(t);
            vis[t]=0;
            if(t==now) break;
        }
        int sccin=0;
        for(auto it=s.begin();it!=s.end();it++) for(int t:gr[*it]) if(s.find(t)==s.end()) sccin++;
        idc[n+sccs]=sccin;
    }
    s.clear();
}

void solve(int now){
    vis[now]=1;
    fin[now]=1;
    for(int nx:g[now]){
        if(vis[nx]) continue;
        solve(nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        memset(idc,0,sizeof(idc));
        memset(fin,0,sizeof(fin));
        cnt=0;
        for(int i=1;i<=100000;i++){
            g[i].clear();
            gr[i].clear();
        }
        sccs=0;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            gr[b].push_back(a);
            idc[b]++;
        }
        int res=0;
        for(int i=1;i<=n;i++) if(!idc[i]){
            solve(i);
            res++;
        }
        for(int i=1;i<=n;i++) if(!num[i] && !fin[i]) dfs(i);
        for(int i=1;i<=n+sccs;i++) res+=(!idc[i] && !fin[i]);
        cout << res << '\n';
    }
    return 0;
}