#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll ans=0;
    ll x,y;
    cin >> n >> x;
    for(int i=1;i<n;i++){
        cin >> y;
        ans+=2*x*x+2*y*y;
        x=y;
    }
    cout << ans;
    return 0;
}