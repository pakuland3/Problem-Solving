#include <bits/stdc++.h>
using namespace std;

int n,m,k,x;
vector<int> graph[300001];
vector<int> ans;
bool vis[300001];
int dp[300001];

void bfs(){
    dp[x]=0;
    vis[x]=true;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            if(!vis[graph[now][i]]){
                dp[graph[now][i]]=dp[now]+1;
                vis[graph[now][i]]=true;
                q.push(graph[now][i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k >> x;
    for(int i=0;i<m;i++){int a,b; cin >> a >> b;graph[a].push_back(b);}
    bfs();
    for(int i=1;i<=n;i++){if(dp[i]==k) ans.push_back(i);}
    sort(ans.begin(),ans.end());
    for(int o:ans) cout << o << '\n';
    if(ans.empty()) cout << -1;
}