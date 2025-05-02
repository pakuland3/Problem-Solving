#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll r[500001],c[500001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    while(q--){
        ll qq,rr,v;
        cin >> qq >> rr >> v;
        if(qq==1) r[--rr]+=v;
        else c[--rr]+=v;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << r[i]+c[j] << ' ';
        cout << '\n';
    }
    return 0;
}