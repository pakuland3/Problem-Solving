#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n),d(n+1,0);
    for(int &t:a) cin >> t;
    d[0]=1;
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,1},0});
    while(!q.empty()){
        int now=q.front().first.first;
        int s=q.front().first.second;
        int time=q.front().second;
        q.pop();
        if(time==m || now>=n) continue;
        if(s+a[now]>d[now+1]) d[now+1]=s+a[now];
        q.push({{now+1,s+a[now]},time+1});
        if(now==n-1) continue;
        if(s/2+a[now+1]>d[now+2]) d[now+2]=s/2+a[now+1];
        q.push({{now+2,s/2+a[now+1]},time+1});
    }
    int ans=1;
    for(int i=1;i<=n;i++) ans=max(ans,d[i]);
    cout << ans;
    return 0;
}