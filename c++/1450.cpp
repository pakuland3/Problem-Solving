#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
ll r;
vector<ll> a,b,c,d;

void solve(int idx, ll cs, vector<ll> &e, vector<ll> &f){
    for(int i=idx+1;i<e.size();i++){
        cs+=e[i];
        f.push_back(cs);
        solve(i,cs,e,f);
        cs-=e[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> r;
    a.resize(n/2);
    b.resize(n/2+n%2);
    for(ll &t:a) cin >> t;
    for(ll &t:b) cin >> t;
    solve(-1,0,a,c);
    solve(-1,0,b,d);
    sort(d.begin(),d.end());
    ll res=1;
    for(ll &t:c) res+=upper_bound(d.begin(),d.end(),r-t)-d.begin();
    for(ll &t:c) res+=(t<=r);
    for(ll &t:d) res+=(t<=r);
    cout << res;
    return 0;
}