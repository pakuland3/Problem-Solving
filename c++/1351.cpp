#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n,p,q;
unordered_map<ll, ll> um;

ll solve(ll x){
    if(um.find(x)!=um.end()) return um[x];
    return um[x]=solve(x/p)+solve(x/q);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    um[0]=1;
    cin >> n >> p >> q;
    cout << solve(n);
    return 0;
}