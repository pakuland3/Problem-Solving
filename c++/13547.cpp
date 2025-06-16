#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,m,rt,cur=0;
int cnt[1000001];
int a[100001];
int res[100001];

struct qq{
    int l,r,n;
    bool operator<(qq &o){
        int x=r/rt;
        int y=o.r/rt;
        return x==y?l<o.l:x<y;
    }
};

qq q[100001];

void solve(int idx, int add){
    if(add){
        if(cnt[a[idx]]++==0) cur++;
    }
    else{
        if(--cnt[a[idx]]==0) cur--;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    rt=sqrt(n);
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> q[i].l >> q[i].r;
        q[i].n=i;
    }
    sort(q,q+m);
    int lo=1,hi=0;
    for(int i=0;i<m;i++){
        while(lo<q[i].l) solve(lo++,0);
        while(lo>q[i].l) solve(--lo,1);
        while(hi>q[i].r) solve(hi--,0);
        while(hi<q[i].r) solve(++hi,1);
        res[q[i].n]=cur;
    }
    for(int i=0;i<m;i++) cout << res[i] << '\n';
    return 0;
}