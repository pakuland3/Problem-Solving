#include <bits/stdc++.h>
#define MOD 1000000007ll
typedef long long ll;
using namespace std;

// using Fermat Theorem or Extended Euclidean Algorithm

ll p(ll a, int n){
    if(n==0) return 1;
    if(n==1) return a;
    ll b=p(a,n/2); b*=b; b%=MOD;
    if(n%2) return (b*a)%MOD;
    return b;
}

pair<ll,pair<ll,ll>> xGCD(ll a, ll b){
    if(b==0) return {a,{1,0}};
    pair<ll,pair<ll,ll>> ret=xGCD(b,a%b);
    ll g,x,y;
    g=ret.first;
    tie(x,y)=ret.second;
    return {g,{y,x-a/b*y}};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,k,t=1,b=1;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        t*=n--;
        t%=MOD;
        b*=(ll)(i+1);
        b%=MOD;
    }
    // cout << (t*p(b,MOD-2))%MOD;
    ll inv=xGCD(MOD,b).second.second;
    inv+=MOD*(-inv/MOD+1);
    inv%=MOD;
    cout << (t*inv)%MOD;
    return 0;
}