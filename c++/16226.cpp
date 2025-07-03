#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

vector<pair<pair<int,int>,int>> g[100002];
int vis[200001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int res=n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].fi >> a[i].se;
        g[a[i].fi].push_back({{a[i].se,0},i});
        g[a[i].fi+1].push_back({{a[i].se,1},i});
    }
    auto comp=[&](auto l, auto r) -> bool {
        return l.fi.fi<r.fi.fi;
    };
    for(int i=1;i<100002;i++) sort(g[i].begin(),g[i].end(),comp);
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        int r=a[i].fi;
        int idx=lower_bound(g[r].begin(),g[r].end(),pair<pair<int,int>,int>({a[i].se,0},0),comp)-g[r].begin();
        for(int j=idx-1;j>=0;j--){
            if(g[r][j].fi.se) break;
            vis[g[r][j].se]=1;
            res--;
        }
        for(int j=idx+1;j<g[r].size();j++){
            if(g[r][j].fi.se) break;
            vis[g[r][j].se]=1;
            res--;
        }
    }
    cout << res;
    return 0;
}