#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    bitset<65> bs(n),ans;
    int cnt;
    for(int i=0;i<65;i++) if(bs[i]) cnt=i;
    for(int i=0;i<cnt;i++) ans[i]=!bs[i];
    if(ans.to_ullong()==0) cout << "1\n" << n;
    else cout << "2\n" << ans.to_ullong() << '\n' << n;
    return 0;
}