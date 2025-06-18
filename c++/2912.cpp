// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int n,c,rt;
// int a[300001];
// int cnt[10001];
// int res[10001];

// struct query{
//     int l,r,n;
//     bool operator<(query &o){
//         int x=r/rt;
//         int y=o.r/rt;
//         return x==y?l<o.l:x<y;
//     }
// } q[10001];

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n >> c;
//     rt=sqrt(n);
//     for(int i=1;i<=n;i++) cin >> a[i];
//     int m;
//     cin >> m;
//     for(int i=0;i<m;i++){
//         cin >> q[i].l >> q[i].r;
//         q[i].n=i;
//     }
//     sort(q,q+m);
//     mt19937 mt((uint64_t) new char);
//     int lo=1,hi=0;
//     for(int i=0;i<m;i++){
//         while(lo<q[i].l) cnt[a[lo++]]--;
//         while(lo>q[i].l) cnt[a[--lo]]++;
//         while(hi<q[i].r) cnt[a[++hi]]++;
//         while(hi>q[i].r) cnt[a[hi--]]--;
//         int l=(q[i].r-q[i].l+1);
//         uniform_int_distribution<int> uni(0,q[i].r-q[i].l);
//         for(int j=0;j<30;j++){
//             int num=a[q[i].l+uni(mt)];
//             if(cnt[num]>(q[i].r-q[i].l+1)/2){
//                 res[q[i].n]=num;
//                 break;
//             }
//         }
//     }
//     for(int i=0;i<m;i++){
//         if(res[i]) cout << "yes " << res[i] << '\n';
//         else cout << "no\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,c,rt;
int a[300001];
int cnt[10001];
int res[10001];

struct query{
    int l,r,n;
    bool operator<(query &o){
        int x=r/rt;
        int y=o.r/rt;
        return x==y?l<o.l:x<y;
    }
} q[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> c;
    rt=sqrt(n);
    for(int i=1;i<=n;i++) cin >> a[i];
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> q[i].l >> q[i].r;
        q[i].n=i;
    }
    sort(q,q+m);
    int lo=1,hi=0;
    for(int i=0;i<m;i++){
        while(lo<q[i].l) cnt[a[lo++]]--;
        while(lo>q[i].l) cnt[a[--lo]]++;
        while(hi<q[i].r) cnt[a[++hi]]++;
        while(hi>q[i].r) cnt[a[hi--]]--;
        int t=1;
        for(int j=2;j<=10000;j++) if(cnt[t]<cnt[j]) t=j;
        if(cnt[t]>(q[i].r-q[i].l+1)/2) res[q[i].n]=t;
    }
    for(int i=0;i<m;i++){
        if(res[i]) cout << "yes " << res[i] << '\n';
        else cout << "no\n";
    }
    return 0;
}