#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k,n;
    cin >> k >> n;
    vector<ll> p(k);
    ll maxi=0;
    for(ll &t:p){
        cin >> t;
        maxi=max(maxi,t);
    }
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    unordered_set<ll> us;
    for(ll &t:p){
        pq.push(t);
        us.insert(t);
    }
    for(int i=1;i<n;i++){
        ll c=pq.top();
        pq.pop();
        for(ll &t:p){
            if(us.find(c*t)!=us.end()) continue;
            if(pq.size()>n && c*t>maxi) continue;
            maxi=max(maxi,c*t);
            us.insert(c*t);
            pq.push(c*t);
        }
    }
    cout << pq.top();
    return 0;
}