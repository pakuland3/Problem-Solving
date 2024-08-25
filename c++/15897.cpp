#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    ll res=n;
    for(ll i=1,j;i<n;i+=j){
        j=(n-1)%i/((n-1)/i)+1;
        res+=(n-1)/i*j;
    }
    cout << res;
    return 0;
}