#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    int x,y;
};

vector<p> a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    a.resize(n);
    ll ans=0;
    for(p &t:a) cin >> t.x >> t.y;
    sort(a.begin(),a.end(),[&](p &l, p &r)->bool {
        if(l.x==r.x) return l.y<r.y;
        return l.x<r.x;
    });
    for(int i=1;i<n;i+=2) ans+=a[i].y-a[i-1].y;
    sort(a.begin(),a.end(),[&](p &l, p &r)->bool {
        if(l.y==r.y) return l.x<r.x;
        return l.y<r.y;
    });
    for(int i=1;i<n;i+=2) ans+=a[i].x-a[i-1].x;
    cout << ans;
    return 0;
}