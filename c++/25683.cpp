#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    ll ans=0;
    cin >> n;
    vector<pair<int, int>> m(n);
    for(auto &p:m) cin >> p.first >> p.second;
    for(int i=n-2;i>-1;i--) ans+=(ll)m[n-1].second*m[i].second*m[i].first;
    cout << ans;
    return 0;
}