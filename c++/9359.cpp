#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a,b,n;

ll solve(ll n, vector<int> &p){
    ll res=n;
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
        if(odd) res-=n/div;
        else res+=n/div;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++){
        vector<int> p;
        cin >> a >> b >> n;
        int cnt=sqrt(n);
        for(int i=2;i<=cnt;i++){
            if(n%i==0){
                p.push_back(i);
                while(n%i==0) n/=i;
            }
        }
        if(n>1) p.push_back(n);
        cout << "Case #" << tt+1 << ": " << solve(b,p)-solve(a-1,p) << '\n';
    }
    return 0;
}