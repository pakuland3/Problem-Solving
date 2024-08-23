#include <bits/stdc++.h>
#define ES ((ll)E-(ll)S+1LL)
#define SIZE 100000*4
typedef long long ll;
using namespace std;

ll tree[SIZE],lazy[SIZE];

void update_lazy(int node, int S, int E){
    if(lazy[node]!=0){
        tree[node]+=ES*lazy[node];
        if(S!=E) for(int i:{0,1}) lazy[2*node+i]+=lazy[node];
        lazy[node]=0;
    }
}

void update_range(int L, int R, ll k, int node, int S, int E){
    update_lazy(node,S,E);
    if(R<S || E<L) return;
    if(L<=S && E<=R){
        tree[node]+=ES*k;
        if(S!=E) for(int i:{0,1}) lazy[2*node+i]+=k;
        return;
    }
    int MID=(S+E)/2;
    update_range(L,R,k,2*node,S,MID);
    update_range(L,R,k,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int X, int node, int S, int E){
    update_lazy(node,S,E);
    if(X<S || E<X) return 0;
    if(S==E) return tree[node];
    int MID=(S+E)/2;
    return query(X,2*node,S,MID)+query(X,2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        ll a;
        cin >> a;
        update_range(i,i,a,1,1,n);
    }
    int m;
    cin >> m;
    while(m--){
        int q,a,b;
        ll k;
        cin >> q >> a;
        if(q==1){
            cin >> b >> k;
            update_range(a,b,k,1,1,n);
        }
        else cout << query(a,1,1,n) << '\n';
    }
    return 0;
}