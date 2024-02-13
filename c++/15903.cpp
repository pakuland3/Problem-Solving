#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

priority_queue<ll,vector<ll>,greater<ll>> pq;
int n,m;
int ini;
ll ans=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){cin >> ini;pq.push(ini);}
    for(int i=0;i<m;i++){
        ll a=pq.top();
        pq.pop();
        pq.push(a+pq.top());
        pq.push(a+pq.top());
        pq.pop();
    }
    for(int i=0;i<n;i++){ans+=pq.top();pq.pop();}
    cout << ans;
}