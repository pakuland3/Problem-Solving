#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,x,ans=0,d=0,cnt;
    cin >> n >> x;
    vector<ll> a(n),b(n),c(n);
    for(ll &t:a) cin >> t;
    for(ll &t:b) cin >> t;
    c[n-1]=a[n-1];
    for(int i=n-2;i>-1;i--) c[i]=max(c[i+1]-b[i+1],a[i]);
    for(int i=0;i<n;i++){
        d+=b[i];
        if(d<c[i]){cout << -1; return 0;}
        cnt=(d-c[i])/x;
        ans+=cnt;
        d-=cnt*x;
    }
    cout << ans;
    return 0;
}