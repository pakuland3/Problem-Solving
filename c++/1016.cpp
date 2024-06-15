#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll mini,maxi;
    int cnt=0;
    cin >> mini >> maxi;
    vector<bool> a(maxi-mini+1,1);
    for(ll j=2;j*j<=mini;j++) if(mini%(j*j)==0){a[0]=0; cnt=1;}
    for(ll j=2;j<=(ll)1e6;j++){
        ll add;
        if(mini<=j*j) add=j*j-mini;
        else add=j*j-mini%(j*j);
        for(ll k=0;mini+add+k<=maxi;k+=j*j){
            if(a[k+add]) cnt++;
            a[k+add]=0;
        }
    }
    cout << maxi-mini+1-cnt;
    return 0;
}