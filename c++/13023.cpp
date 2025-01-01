#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool vis[2000];
int n,m,a,b;
vector<int> graph[2000];

void dfs(int node, int cnt){
    if(cnt>4){
        cout << 1;
        exit(0);
    }
    for(int i=0;i<graph[node].size();i++){
        if(vis[graph[node][i]]) continue;
        vis[graph[node][i]]=1;
        dfs(graph[node][i],cnt+1);
        vis[graph[node][i]]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        dfs(i,1);
    }
    cout << 0;
    return 0;
}

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// bool vis[2000];
// int n,m,a,b;
// vector<int> graph[2000];

// int dfs(int node){
//     int cnt=0;
//     for(int i=0;i<graph[node].size();i++){
//         if(vis[graph[node][i]]) continue;
//         vis[graph[node][i]]=1;
//         cnt=max(cnt,dfs(graph[node][i])+1);
//         if(cnt>3){
//             cout << 1;
//             exit(0);
//         }
//         vis[graph[node][i]]=0;
//     }
//     return cnt;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n >> m;
//     for(int i=0;i<m;i++){
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     for(int i=0;i<n;i++){
//         memset(vis,0,sizeof(vis));
//         vis[i]=1;
//         dfs(i);
//     }
//     cout << 0;
//     return 0;
// }