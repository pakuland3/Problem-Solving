#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,sum=0,cntT=0,cntO=0,tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        sum+=tmp;
        cntT+=tmp/2;
        cntO+=tmp%2;
    }
    if(sum%3!=0 || cntT<sum/3){cout << "NO\n"; return;}
    if(cntT==sum/3){cout << "YES\n"; return;}
    if((cntT-sum/3)*2+cntO==sum/3) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // int t; cin >> t; while(t--) solve();
    solve();
    return 0;
}