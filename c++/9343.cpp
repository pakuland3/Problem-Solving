#include <bits/stdc++.h>
#define MOD 1000000007ll
typedef long long ll;
using namespace std;

pair<ll,pair<ll,ll>> xGCD(ll a, ll b){
    if(b==0) return {a,{1,0}};
    auto ret=xGCD(b,a%b);
    ll g,x,y;
    g=ret.first;
    tie(x,y)=ret.second;
    return {g,{y,x-a/b*y}};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll t=1,b=n+1;
        for(int i=0;i<n;i++){
            t*=2*n-(ll)i;
            b*=(ll)(i+1);
            t%=MOD;
            b%=MOD;
        }
        auto res=xGCD(MOD,b);
        if(res.second.second<0) res.second.second+=(1-res.second.second/MOD)*MOD;
        res.second.second%=MOD;
        cout << (res.second.second*t)%MOD << '\n';
    }
    return 0;
}