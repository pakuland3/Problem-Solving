#include <bits/stdc++.h>
using namespace std;

int n,m;
int prereq[1001];
int dp[1001];
vector<int> graph[1001];
vector<int> req[1001];
queue<int> q;

void solve(){
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<req[now].size();i++) dp[now]=max(dp[now],dp[req[now][i]]+1);
        for(int i=0;i<graph[now].size();i++){
            prereq[graph[now][i]]--;
            if(prereq[graph[now][i]]==0) q.push(graph[now][i]);
        }
    }
    for(int i=1;i<=n;i++) cout << dp[i] << ' ';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int A,B; cin >> A >> B;
        graph[A].push_back(B);
        req[B].push_back(A);
    }
    for(int i=1;i<=n;i++) prereq[i]=req[i].size();
    for(int i=1;i<=n;i++) if(prereq[i]==0){q.push(i);dp[i]=1;}
    solve();
}