#include <bits/stdc++.h>
using namespace std;

int n,t[10001],d[10001]={0,},ans=0,inn,cnt[10001];
queue<int> q;
vector<int> nxt[10001];

void solve(){
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<nxt[now].size();i++){
            cnt[nxt[now][i]]--;
            d[nxt[now][i]]=max(d[nxt[now][i]],d[now]+t[nxt[now][i]]);
            if(cnt[nxt[now][i]]==0) q.push(nxt[now][i]);
        }
        ans=max(ans,d[now]);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> cnt[i];
        if(cnt[i]==0){q.push(i); d[i]=t[i];}
        for(int j=0;j<cnt[i];j++){
            cin >> inn;
            nxt[inn].push_back(i);
        }
    }
    solve();
    return 0;
}