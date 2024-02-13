#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n;
    int ans=0;
    pair<int, int> p[100000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i].first >> p[i].second;
    sort(p,p+n,[](pair<int, int> l,pair<int, int> r) -> bool {return l.first<r.first;});
    int mini=n+1;
    for(int i=0;i<n;i++){
        if(p[i].second<mini){ans++;mini=p[i].second;}
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while(t--) solve();
}