#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<ll> powof2(61);
    for(int i=0;i<61;i++) powof2[i]=pow(2,i);
    int t;
    cin >> t;
    while(t--){
        ll n,k,ans;
        cin >> n >> k;
        if(k>60){cout << "0\n"; continue;}
        ans=n/powof2[k];
        ans=ans/2+ans%2;
        cout << ans << '\n';
    }
    return 0;
}