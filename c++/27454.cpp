#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k,y;
    cin >> n >> k >> y;
    vector<ll> a(n+1),pfx(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++) pfx[i]=a[i]+pfx[i-1];
    ll res=INT64_MAX;
    if(k<3){
        for(int i=1;i<=n;i++) res=min(res,abs(y-a[i]));
        cout << (k&1?0:res);
        exit(0);
    }
    int lc=k/2+(k&1);
    int rc=k/2;
    for(int i=k-1;i<=n;i++){
        ll l,r,m;
        int med=(i+i-(k-1)+1)/2+!((k-1)&1);
        if(y<a[med]){
            med--;
            if(a[med]<y) m=y;
            else m=a[med];
            l=y+pfx[med]-pfx[med-(lc-1)];
            r=pfx[i]-pfx[med];
        }
        else{
            m=a[med];
            l=pfx[med]-pfx[med-lc];
            r=y+pfx[i]-pfx[med];
        }
        res=min(res,r-l+m*(lc-rc));
    }
    cout << res;
    return 0;
}