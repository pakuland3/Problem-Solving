#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[100001],rt,n,t;
ll c[1000001],res[100001],sum;

struct query{
    int l,r,n;
    bool operator<(query &o){
        int x=r/rt;
        int y=o.r/rt;
        return x==y?l<o.l:x<y;
    }
} q[100001];

void solve(int x, int add){
    if(add){
        sum+=x*(2*c[x]+1);
        c[x]++;
    }
    else{
        sum+=x*(-2*c[x]+1);
        c[x]--;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> t;
    rt=sqrt(n);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<t;i++) cin >> q[i].l >> q[i].r,q[i].n=i;
    sort(q,q+t);
    int lo=1,hi=0;
    for(int i=0;i<t;i++){
        while(q[i].l<lo) solve(a[--lo],1);
        while(q[i].l>lo) solve(a[lo++],0);
        while(q[i].r>hi) solve(a[++hi],1);
        while(q[i].r<hi) solve(a[hi--],0);
        res[q[i].n]=sum;
    }
    for(int i=0;i<t;i++) cout << res[i] << '\n';
    return 0;
}