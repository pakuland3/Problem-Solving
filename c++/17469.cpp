#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

set<int> s[100001];
pair<int,int> q[1100001];
int anc[100001];
int parent[100001];

int getParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(s[a].size()>s[b].size()){
        for(auto it=s[b].begin();it!=s[b].end();it++) s[a].insert(*it);
        s[b].clear();
        parent[b]=a;
    }
    else{
        for(auto it=s[a].begin();it!=s[a].end();it++) s[b].insert(*it);
        s[a].clear();
        parent[a]=b;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,Q,t;
    cin >> n >> Q;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=2;i<=n;i++){
        cin >> t;
        anc[i]=t;
    }
    for(int i=1;i<=n;i++){
        cin >> t;
        s[i].insert(t);
    }
    for(int i=0;i<n+Q-1;i++) cin >> q[i].fi >> q[i].se;
    reverse(q,q+n+Q-1);
    vector<int> ans;
    for(int i=0;i<n+Q-1;i++){
        if(q[i].fi&1) unionParent(q[i].se,anc[q[i].se]);
        else ans.push_back(s[getParent(q[i].se)].size());
    }
    reverse(ans.begin(),ans.end());
    for(int t:ans) cout << t << '\n';
    return 0;
}