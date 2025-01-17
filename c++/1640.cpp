#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    bitset<1000> rr,cc;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        for(int j=0;j<m;j++) if(a[j]=='1') rr[i].flip(),cc[j].flip();
    }
    if(rr.none() && cc.none()){
        cout << 0;
        return 0;
    }
    int r=rr.count(),c=cc.count();
    int ans=2001;
    if((n-r)%2 && (m-c)%2) ans=min(ans,n-r+m-c);
    if((n-r)%2==0 && c%2) ans=min(ans,n-r+c);
    if(r%2 && (m-c)%2==0) ans=min(ans,r+m-c);
    if(r%2==0 && c%2==0) ans=min(ans,r+c);
    cout << ans;
    return 0;
}