#include <bits/stdc++.h>
using namespace std;

int n,m,A,B,start=0;
vector<int> graph[32001];
int cnt[32001]={0,};
priority_queue<int,vector<int>,greater<int>> pq;

void solve(){
    while(!pq.empty()){
        int now=pq.top();
        cout << now << ' ';
        pq.pop();
        for(int i=0;i<graph[now].size();i++){
            cnt[graph[now][i]]--;
            if(cnt[graph[now][i]]==0) pq.push(graph[now][i]);
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
    for(int i=1;i<=n;i++) if(cnt[i]==0) pq.push(i);
    solve();
    return 0;
}