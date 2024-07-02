#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(ll &t:a) cin >> t;
    for(ll &t:b) cin >> t;
    for(int i=0;i<n;i++){
        int ans=max(0,(int)(upper_bound(b.begin()+i,b.end(),a[i])-(b.begin()+i)-1));
        cout << ans << ' ';
    }
    return 0;
}