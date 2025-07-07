#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int parent[200001];
int ac[200001];

int getParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a>b) parent[a]=b;
    else parent[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=2;i<=n;i++) cin >> ac[i];
    vector<int> ans;
    vector<pair<int,pair<int,int>>> Q(q+n-1);
    for(auto &t:Q){
        cin >> t.fi >> t.se.fi;
        if(t.fi) cin >> t.se.se;
    }
    reverse(Q.begin(),Q.end());
    for(auto &t:Q){
        if(t.fi) ans.push_back(getParent(t.se.fi)==getParent(t.se.se));
        else unionParent(t.se.fi,ac[t.se.fi]);
    }
    reverse(ans.begin(),ans.end());
    for(int &t:ans) cout << (t?"YES":"NO") << '\n';
    return 0;
}