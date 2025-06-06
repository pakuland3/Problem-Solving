// Tarjan Algorithm
// #include <bits/stdc++.h>
// #define MAX 10001
// typedef long long ll;
// using namespace std;

// int num[MAX];
// int vis[MAX];
// int low[MAX];
// int cnt=0;
// vector<int> g[MAX];
// vector<vector<int>> scc;
// stack<int> st;

// void dfs(int now){
//     vis[now]=1;
//     num[now]=++cnt;
//     low[now]=cnt;
//     st.push(now);
//     for(int nx:g[now]){
//         if(!num[nx]){
//             dfs(nx);
//             low[now]=min(low[now],low[nx]);
//         }
//         else if(vis[nx]) low[now]=min(low[now],num[nx]);
//     }
//     if(low[now]==num[now]){
//         vector<int> a;
//         while(st.size()){
//             a.push_back(st.top());
//             st.pop();
//             vis[a.back()]=0;
//             if(now==a.back()) break;
//         }
//         sort(a.begin(),a.end());
//         scc.push_back(a);
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int v,e;
//     cin >> v >> e;
//     while(e--){
//         int a,b;
//         cin >> a >> b;
//         g[a].push_back(b);
//     }
//     for(int i=1;i<=v;i++) if(!num[i]) dfs(i);
//     sort(scc.begin(),scc.end(),[](auto &l, auto &r) -> bool { return l[0]<r[0]; });
//     cout << scc.size() << '\n';
//     for(auto &vv:scc){
//         for(int &t:vv) cout << t << ' ';
//         cout << "-1\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int vis[10001];
vector<int> order,g[10001],gr[10001];
int scc[10001];

void dfs(int now){
    if(vis[now]) return;
    vis[now]=1;
    for(int nx:g[now]) dfs(nx);
    order.push_back(now);
}

void dfs_rev(int now, int num){
    if(vis[now]) return;
    vis[now]=1;
    scc[now]=num;
    for(int nx:gr[now]) dfs_rev(nx,num);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v,e;
    cin >> v >> e;
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    for(int i=1;i<=v;i++) dfs(i);
    memset(vis,0,sizeof(vis));
    reverse(order.begin(),order.end());
    int cnt=0;
    for(int x:order) if(!vis[x]) dfs_rev(x,++cnt);
    cout << cnt << '\n';
    vector<vector<int>> ans(cnt);
    for(int i=1;i<=v;i++) ans[scc[i]-1].push_back(i);
    for(int i=0;i<cnt;i++) sort(ans[i].begin(),ans[i].end());
    sort(ans.begin(),ans.end(),[](auto &l, auto &r) -> bool { return l[0]<r[0]; });
    for(vector<int> &a:ans){
        for(int &t:a) cout << t << ' ';
        cout << "-1\n";
    }
    return 0;
}