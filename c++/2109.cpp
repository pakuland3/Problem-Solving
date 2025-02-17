#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct a{
    int d,w;
};

int d[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int ans=0;
    cin >> n;
    vector<a> b(n);
    for(a &t:b) cin >> t.w >> t.d;
    sort(b.begin(),b.end(),[&](a &l, a &r) -> bool {
        return l.w>r.w;
    });
    for(int i=0;i<n;i++){
        while(d[b[i].d] && b[i].d>0) b[i].d--;
        if(b[i].d==0) continue;
        ans+=b[i].w;
        d[b[i].d]=1;
    }
    cout << ans;
    return 0;
}