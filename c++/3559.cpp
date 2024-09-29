#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a,b,p,q;

ll solve(ll n){
    ll res=0;
    for(int i=1;i<63;i++){
        ll tmp=n;
        for(int j=0;j<i;j++) tmp/=p;
        for(int j=0;j<i;j++){
            res+=tmp-tmp/p-tmp/q+tmp/p/q;
            tmp/=q;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> p >> q;
    cout << solve(b)-solve(a-1);
    return 0;
}