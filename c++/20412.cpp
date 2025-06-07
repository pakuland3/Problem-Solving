#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll m,x1,x2,s,a,c;

ll fastpow(ll a, int b){
    if(b==0 || b==1) return (b==1?a:1);
    ll t=fastpow(a,b/2);
    return ((t*t)%m*(b&1?a:1))%m;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> s >> x1 >> x2;
    if(s>x1) a=((x1-x2+m)%m*fastpow(s-x1,m-2))%m;
    else a=((x2-x1+m)%m*fastpow(x1-s,m-2))%m;
    c=(x1-a*s+m*m)%m;
    cout << a << ' ' << c;
    return 0;
}