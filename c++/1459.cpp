#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll x,y,w,s;
    cin >> x >> y >> w >> s;
    ll ans=min((x+y)*w,min(x,y)*s+abs(x-y)*w);
    if(abs(x-y)%2) ans=min(ans,(min(x,y)+abs(x-y)-1)*s+w);
    else ans=min(ans,(min(x,y)+abs(x-y))*s);
    cout << ans;
    return 0;
}