#include <bits/stdc++.h>
#define SIZE 1000000
typedef long long ll;
using namespace std;

ll tree[4*SIZE],lazy[4*SIZE];
ll n,m,k,a,b,c,d;

void update_lazy(int node, ll S, ll E){
    if(lazy[node]!=0){
        tree[node]+=(E-S+1)*lazy[node];
        if(S!=E){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update_range(int L, int R, ll V, int node, ll S, ll E){
    update_lazy(node,S,E);
    if(R<S || E<L) return;
    if(L<=S && E<=R){
        tree[node]+=(E-S+1)*V;
        if(S!=E){
            lazy[2*node]+=V;
            lazy[2*node+1]+=V;
        }
        return;
    }
    int MID=(S+E)/2;
    update_range(L,R,V,2*node,S,MID);
    update_range(L,R,V,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int L, int R, int node, int S, int E){
    update_lazy(node,S,E);
    if(R<S || E<L) return 0;
    if(L<=S && E<=R) return tree[node];
    int MID=(S+E)/2;
    return query(L,R,2*node,S,MID)+query(L,R,2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        update_range(i+1,i+1,a,1,1,n);
    }
    for(int i=0;i<m+k;i++){
        cin >> a;
        if(a==2){
            cin >> b >> c;
            cout << query(b,c,1,1,n) << '\n';
        }
        else{
            cin >> b >> c >> d;
            update_range(b,c,d,1,1,n);
        }
    }
    return 0;
}