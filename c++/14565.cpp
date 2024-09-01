#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

pair<ll,pair<ll,ll>> xGCD(ll a, ll b){
    if(b==0) return {a,{1,0}};
    pair<ll,pair<ll,ll>> ret=xGCD(b,a%b);
    ll g,x,y;
    g=ret.first;
    tie(x,y)=ret.second;
    return {g,{y,x-(a/b)*y}};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll a,n;
    cin >> n >> a;
    cout << n-a << ' ';
    auto p=xGCD(a,n);
    if(p.first==1){
        ll ans=p.second.first;
        if(ans<0) ans+=(-ans/n+1)*n;
        cout << ans;
    }
    else cout << -1;
    return 0;
}