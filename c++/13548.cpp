#include <bits/stdc++.h>
#define SIZE 100001
typedef long long ll;
using namespace std;

int rt;
int a[100001];
int res[100001];
int cnt[100001];
int cc[100001];
int maxi=0;

struct query{
    int l,r,n;
    bool operator<(query &o){
        int x=r/rt;
        int y=o.r/rt;
        return x==y?l<o.l:x<y;
    }
} q[100001];

void solve(int num, int add){
    if(add){
        if(cc[cnt[num]]) cc[cnt[num]]--;
        cnt[num]++;
        cc[cnt[num]]++;
        maxi=max(maxi,cnt[num]);
    }
    else{
        cc[cnt[num]]--;
        if(!cc[cnt[num]] && maxi==cnt[num]) maxi--;
        cnt[num]--;
        cc[cnt[num]]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
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
        while(lo<q[i].l) solve(a[lo++],0);
        while(lo>q[i].l) solve(a[--lo],1);
        while(hi>q[i].r) solve(a[hi--],0);
        while(hi<q[i].r) solve(a[++hi],1);
        res[q[i].n]=maxi;
    }
    for(int i=0;i<m;i++) cout << res[i] << '\n';
    return 0;
}