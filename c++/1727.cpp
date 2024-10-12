#include <bits/stdc++.h>
#define FI first
#define SE second
#define piii pair<int,pair<int,int>>
typedef long long ll;
using namespace std;

bool c[1000],d[1000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    for(int &t:a) cin >> t;
    for(int i=0;i<m;i++){
        cin >> b[i];
        for(int j=0;j<n;j++) pq.push({abs(b[i]-a[j]),{j,i}});
    }
    int cnt=min(n,m);
    ll res=0;
    while(cnt--){
        piii p=pq.top();
        pq.pop();
        if(c[p.SE.FI] || d[p.SE.SE]){
            cnt++;
            continue;
        }
        res+=(ll)p.FI;
        c[p.SE.FI]=1;
        d[p.SE.SE]=1;
    }
    cout << res;
    return 0;
}