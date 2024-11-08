#include <bits/stdc++.h>
#define SIZE 100001
typedef long long ll;
using namespace std;

int tree[SIZE*4];

void update(int x, int v, int node, int s, int e){
    if(e<x || x<s) return;
    if(s==e){
        if(tree[node] && v%2) tree[node]=0;
        else if(!tree[node] && v%2==0) tree[node]=1;
        return;
    }
    int mid=(s+e)/2;
    update(x,v,2*node,s,mid);
    update(x,v,2*node+1,mid+1,e);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int l, int r, int node, int s, int e){
    if(e<l || r<s) return 0;
    if(l<=s && e<=r) return tree[node];
    int mid=(s+e)/2;
    return query(l,r,2*node,s,mid)+query(l,r,2*node+1,mid+1,e);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,a,b,sign;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a;
        update(i,a,1,1,n);
    }
    cin >> m;
    while(m--){
        cin >> sign >> a >> b;
        if(sign==1) update(a,b,1,1,n);
        else if(sign==2) cout << query(a,b,1,1,n) << '\n';
        else cout << b-a+1-query(a,b,1,1,n) << '\n';
    }
    return 0;
}