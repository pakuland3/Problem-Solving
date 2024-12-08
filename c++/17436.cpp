#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, vector<int> &p){
    ll res=0;
    int cnt=1<<p.size();
    for(int i=1;i<cnt;i++){
        ll div=1;
        bool odd=0;
        int j=i;
        int idx=0;
        while(j){
            if(j&1){
                div*=p[idx];
                odd=!odd;
            }
            idx++;
            j>>=1;
        }
        if(odd) res+=n/div;
        else res-=n/div;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll m;
    cin >> n >> m;
    vector<int> p(n);
    for(int &t:p) cin >> t;
    cout << solve(m,p);
    return 0;
}