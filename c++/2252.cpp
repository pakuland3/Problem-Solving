#include <bits/stdc++.h>
using namespace std;

int n,m,A,B;
vector<int> graph[32001];
int cnt[32001]={0,};
queue<int> q;

void solve(){
    while(!q.empty()){
        int now=q.front();
        cout << now << ' ';
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            cnt[graph[now][i]]--;
            if(cnt[graph[now][i]]==0) q.push(graph[now][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> A >> B;
        graph[A].push_back(B);
        cnt[B]++;
    }
    for(int i=1;i<=n;i++) if(cnt[i]==0) q.push(i);
    solve();
    return 0;
}