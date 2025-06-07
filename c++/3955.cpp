#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

pair<ll,pair<ll,ll>> xGCD(ll a, ll b) {   
    if(b==0) return {a,{1,0}};
    pair<ll,pair<ll,ll>> ret=xGCD(b,a%b);
    ll g,x,y;
    g=ret.first;
    tie(x,y)=ret.second;
    return {g,{y,x-(a/b)*y}};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        ll k,c;
        cin >> k >> c;
        if(c==1){
            cout << (k+1<=1e9?to_string(k+1):"IMPOSSIBLE") << '\n';
            continue;
        }
        if(k==1){
            cout << "1\n";
            continue;   
        }
        if(gcd(k,c)!=1){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << (xGCD(c,k).second.first+k)%k << '\n';
    }
    return 0;
}