#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll fastPow(ll a, int b){
    if(b==1) return a;
    ll c=fastPow(a,b/2)%MOD;
    c*=c;
    c%=MOD;
    if(b%2) return (a*c)%MOD;
    return c;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,r;
    cin >> n >> r;
    ll a=1,b=1;
    for(int i=0;i<r;i++){
        a*=(n-(ll)i);
        a%=MOD;
    }
    for(int i=0;i<r;i++){
        b*=(r-(ll)i);
        b%=MOD;
    }
    cout << (a*fastPow(b,MOD-2))%MOD;
    return 0;
}