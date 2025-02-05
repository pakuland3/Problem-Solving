#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll g=-1,s;
    for(ll &t:a) cin >> t;
    for(ll &t:a){
        cin >> s;
        if(g==-1) g=t-s;
        else g=gcd(g,t-s);
    }
    cout << g;
    return 0;
}