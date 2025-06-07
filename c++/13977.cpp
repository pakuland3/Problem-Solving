#include <bits/stdc++.h>
#define M 1000000007
typedef long long ll;
using namespace std;

ll fact[4000001];

ll fastpow(ll a, int b){
    if(b==0 || b==1) return (b&1?a:1);
    ll t=fastpow(a,b/2);
    return ((t*t)%M*(b&1?a:1))%M;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    fact[1]=1;
    for(int i=2;i<4000001;i++) fact[i]=(fact[i-1]*i)%M;
    while(tc--){
        int n,k;
        cin >> n >> k;
        if(k==0 || k==n){
            cout << "1\n";
            continue;
        }
        ll res=fastpow((fact[n-k]*fact[k])%M,M-2);
        cout << (res*fact[n])%M << '\n';
    }
    return 0;
}