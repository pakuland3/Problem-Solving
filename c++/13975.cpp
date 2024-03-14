#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;

void solve(){
    int n,inn; cin >> n;
    ll ans=0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0;i<n;i++){
        cin >> inn; pq.push(inn);
    }
    while(pq.size()!=1){
        ll a=pq.top(); pq.pop();
        ans+=a+pq.top();
        pq.push(a+pq.top());
        pq.pop();
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}