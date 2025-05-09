#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(auto &p:a) cin >> p.fi >> p.se;
    sort(a.begin(),a.end(),[&](auto l, auto r) -> bool { return l.fi>r.fi; });
    int idx=0;
    int ans=0;
    priority_queue<int> pq;
    for(int i=n;i>0;i--){
        while(idx<n && a[idx].fi==i) pq.push(a[idx++].se);
        if(pq.empty()) continue;
        ans+=pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}