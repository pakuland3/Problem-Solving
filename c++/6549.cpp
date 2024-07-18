#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll a[100001];

ll solve(int l, int r){
    if(l==r) return a[l];
    int mid=(l+r)/2;
    ll s=(l+r)/2,e=s+1;
    ll curh;
    if(a[s]>a[e]){
        curh=a[s];
        e--;
    }
    else{
        curh=a[e];
        s++;
    }
    ll tmp=curh;
    while(s!=l || e!=r){
        if(s==l || e==r){
            if(s==l){
                e++;
                curh=min(curh,a[e]);
            }
            else{
                s--;
                curh=min(curh,a[s]);
            }
            tmp=max(tmp,curh*(e-s+1));
            continue;
        }
        if(a[s-1]>a[e+1]){
            s--;
            curh=min(curh,a[s]);
            tmp=max(tmp,curh*(e-s+1));
        }
        else{
            e++;
            curh=min(curh,a[e]);
            tmp=max(tmp,curh*(e-s+1));
        }
    }
    return max(tmp,max(solve(l,mid),solve(mid+1,r)));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("in","r",stdin);
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++) cin >> a[i];
        cout << solve(0,n-1) << '\n';
    }
    return 0;
}