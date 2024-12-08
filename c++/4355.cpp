#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    while((cin >> n) && n!=0){
        if(n==1){
            cout << "0\n";
            continue;
        }
        ll ans=n;
        int cnt=sqrt(n);
        for(int i=2;i<=cnt;i++){
            if(n%i==0){
                while(n%i==0) n/=i;
                ans-=ans/i;
            }
        }
        if(n>1) ans-=ans/n;
        cout << ans << '\n';
    }
    return 0;
}