#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll s=0,e=5e3;
        while(s<=e){
            ll mid=(s+e)/2;
            if(k*mid*(mid+1)/2ll<=n-1) s=mid+1;
            else e=mid-1;
        }
        int d=(s%2)^(s*(s+1)*k/2ll==n-1);
        cout << ((s/2+s%2)*k-(s*(s+1)*k/2ll-n+1))*(s%2?1:-1) << ' ' << (d?'R':'L') << '\n';
    }
    return 0;
}