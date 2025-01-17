#include <bits/stdc++.h>
#define SIZE 2001
typedef long long ll;
using namespace std;

struct line{
    int s,e;
};

ll tree[SIZE*4];

void update(int x, int node, int s, int e){
    if(e<x || x<s) return;
    if(s==e){
        tree[node]++;
        return;
    }
    int mid=(s+e)/2;
    update(x,2*node,s,mid);
    update(x,2*node+1,mid+1,e);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int x, int node, int s, int e){
    if(e<=x) return 0;
    if(x<s) return tree[node];
    int mid=(s+e)/2;
    return query(x,2*node,s,mid)+query(x,2*node+1,mid+1,e);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    ll res=0;
    cin >> n >> m;
    vector<line> a(m);
    for(line &t:a) cin >> t.s >> t.e;
    sort(a.begin(),a.end(),[&](line &b, line &c) -> bool {
        if(b.s==c.s) return b.e<c.e;
        return b.s<c.s;
    });
    for(int i=0;i<m;i++){
        res+=query(a[i].e,1,1,n);
        update(a[i].e,1,1,n);
    }
    cout << res;
    return 0;
}