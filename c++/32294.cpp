#include <bits/stdc++.h>
#define FI first
#define SE second
#define SIZE 200001
typedef long long ll;
using namespace std;

int dx[]={-1,1};
int n;
int a[SIZE],cnt[SIZE];
ll b[SIZE],dp[SIZE];
bool vis[SIZE];

ll solve(int x){
    if(n<x || x<1) return 0;
    if(dp[x]!=0) return dp[x];
    vis[x]=1;
    for(int i=0;i<2;i++){
        int nx=x+a[x]*dx[i];
        if(1<=nx && nx<=n && vis[nx]) continue;
        ll t=solve(nx);
        dp[x]=(dp[x]==0?t+b[x]:min(dp[x],t+b[x]));
    }
    vis[x]=0;
    return dp[x];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(int j=0;j<2;j++){
            int nx=i+dx[j]*a[i];
            if(n<nx || nx<1) continue;
            cnt[nx]++;
        }
    }
    for(int i=1;i<=n;i++) cin >> b[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
    for(int i=1;i<=n;i++) pq.push({cnt[i],i});
    for(int i=1;i<=n;i++){
        dp[pq.top().SE]=solve(pq.top().SE);
        pq.pop();
    }
    for(int i=1;i<=n;i++) cout << dp[i] << ' ';
    return 0;
}