#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll r,c;
    int t;
    cin >> t;
    while(t--){
        cin >> r >> c;
        ll n=min(r,c);
        ll m=max(r,c);
        ll w=n*(n+1)*(2*n+1)/3-n*(n+1)+n*(n+1)*(m-n)-n*(m-n)+n;
        cout << w << ' ' << w-n << '\n';
    }
    return 0;
}