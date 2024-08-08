#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    bool d=0;
    cin >> n >> q;
    vector<ll> a(n);
    for(ll &t:a){
        cin >> t;
        if(d) t+=*((&t)-1);
        d=1;
    }
    int dif=0;
    while(q--){
        int in,k,s,e;
        cin >> in;
        if(in==3){
            cin >> s >> e;
            s+=dif;
            if(s%n!=0) s%=n;
            else if(s>n) s=n;
            e+=dif;
            if(e%n!=0) e%=n;
            else if(e>n) e=n;
            s--;
            e--;
            if(s>e) cout << a[n-1]-a[s-1]+a[e] << '\n';
            else cout << a[e]-(s!=0?a[s-1]:0) << '\n';
        }
        else{
            cin >> k;
            if(in==1) dif=(dif+n-k)%n;
            else dif=(dif+k)%n;
        }
    }
    return 0;
}