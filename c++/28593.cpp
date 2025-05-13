#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll sum=0;
    unordered_map<ll,ll> m;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        sum+=t;
        if(m.find(t)!=m.end()) m[t]++;
        else m[t]=1;
    }
    int q;
    cin >> q;
    ll d=0;
    while(q--){
        string a;
        cin >> a;
        if(a[0]=='I'){
            ll t;
            cin >> t;
            d+=t;
        }
        else{
            ll x,y;
            cin >> x >> y;
            if(x!=y && m.find(x-d)!=m.end()){
                sum+=(y-x)*m[x-d];
                if(m.find(y-d)!=m.end()) m[y-d]+=m[x-d];
                else m[y-d]=m[x-d];
                m[x-d]=0;
            }
        }
        cout << sum+d*(ll)n << '\n';
    }
    return 0;
}