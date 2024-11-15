#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans=0;
    for(ll &t:a){
        cin >> t;
        ans+=t;
    }
    sort(a.begin(),a.end());
    ll sum=2*a[0]*a[1];
    for(int i=2;i<n;i++) sum+=a[i];
    ans=max(ans,sum);
    sum=2*a[n-1]*a[n-2];
    for(int i=0;i<n-2;i++) sum+=a[i];
    ans=max(ans,sum);
    cout << ans;
    return 0;
}