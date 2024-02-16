#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    if(m*k==1 && n>=2) cout << "-1\n";
    else{
        int a=n-m*k;
        int ans=1;
        if(a>0){
            if(a%(m*k-1)==0) ans+=2*a/(m*k-1);
            else ans+=a/(m*k-1)*2+2;
        }
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--) solve();
}