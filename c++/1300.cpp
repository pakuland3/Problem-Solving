#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    vector<ll> p;
    for(int i=1;i<=n;i++){
        p.push_back(i*i);
    }
    cin >> n;
    ll s=1,e=n*n;
    while(s<e){
        ll mid=(s+e)/2;
        auto it=upper_bound(p.begin(),p.end(),mid);
        if(*it!=1) it--;
        ll cnt=sqrt(*it)+2*(mid-sqrt(*it));;
        if(mid==*it) cnt-=2;
    }
    cout << e;
    return 0;
}