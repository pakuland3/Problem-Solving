#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n,p,q,x,y;
unordered_map<ll,ll> um;

ll solve(ll a){
    if(um.find(a)!=um.end()) return um[a];
    if(a<1) return um[a]=1;
    return um[a]=solve(a/p-x)+solve(a/q-y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> p >> q >> x >> y;
    cout << solve(n);
    return 0;
}