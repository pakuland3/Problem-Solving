#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct kit{
    ll s,l,o;
};

int n;
ll g,k;
vector<kit> a;

bool solve(ll d){
    ll sum=0;
    vector<ll> t;
    for(int i=0;i<n;i++){
        sum+=a[i].s*max(1ll,d-a[i].l);
        if(a[i].o) t.push_back(a[i].s*max(1ll,d-a[i].l));
    }
    sort(t.begin(),t.end(),greater<ll>());
    int c=min((int)k,(int)t.size());
    for(int i=0;i<c;i++) sum-=t[i];
    return sum<=g;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> g >> k;
    a.resize(n);
    for(kit &t:a) cin >> t.s >> t.l >> t.o;
    ll s=3,e=2e9;
    while(s<=e){
        ll mid=(s+e)/2;
        if(solve(mid)) s=mid+1;
        else e=mid-1;
    }
    cout << e;
    return 0;
}