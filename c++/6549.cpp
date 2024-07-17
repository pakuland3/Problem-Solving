#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int a[100001];

ll solve(int l, int r){
    if(l==r) return a[l];
    int s=(l+r)/2,e=s+1;
    ll tmp=min(a[s],a[e])*2;
    while(s!=l || e!=r){
        
    }
    return max(tmp,max(solve(l,s),solve(e,r)));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++) cin >> a[i];
        cout << solve(0,n-1) << '\n';
    }
    return 0;
}