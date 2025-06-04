#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll k;
    cin >> n >> k;
    unordered_map<ll,int> m;
    ll res=0;
    for(int i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        ll t=y-x*k;
        if(m.find(t)!=m.end()){
            res+=m[t];
            m[t]++;
        }
        else m[t]=1;
    }
    cout << res*2;
    return 0;
}