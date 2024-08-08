#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll a,b,c,d;
    cin >> a >> b;
    ll ans=0;
    for(int i=1;i<n;i++){
        cin >> c >> d;
        ans+=a*d+b*c;
        a+=c;
        b+=d;
    }
    cout << ans;
    return 0;
}