#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(9);
    cout << fixed;
    int n;
    ld s,e,eps=pow(10,-12);
    cin >> n;
    vector<ld> c(n),w(n);
    for(ld &t:c) cin >> t;
    cin >> w[0];
    s=eps;
    e=1e6;
    for(int i=1;i<n;i++) cin >> w[i];
    while(e-s>=eps){
        ld a=s+(e-s)/3;
        ld b=e-(e-s)/3;
        ld difofa=0;
        ld difofb=0;
        for(int i=0;i<n;i++){
            difofa+=abs(c[i]*a-w[i]);
            difofb+=abs(c[i]*b-w[i]);
        }
        if(difofa>difofb) s=a;
        else e=b;
    }
    ld ans=0;
    for(int i=0;i<n;i++) ans+=abs(c[i]*s-w[i]);
    cout << ans;
    return 0;
}