#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll phi(ll a){
    ll res=a;
    for(ll i=2;i*i<=a;i++){
        if(a%i) continue;
        res-=res/i;
        while(a%i==0) a/=i;
    }
    if(a>1) res-=res/a;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    ll c=sqrt(n);
    for(ll i=1;i<=c;i++){
        if(n%i) continue;
        if(phi(i)==n/i){
            cout << i;
            return 0;
        }
    }
    for(ll i=c;i>0;i--){
        if(n%i) continue;
        if(phi(n/i)==i){
            cout << n/i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}