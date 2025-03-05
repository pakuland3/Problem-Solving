#include <bits/stdc++.h>
#define SIZE 20001
using namespace std;

int tree[SIZE*4];
int lazy[SIZE*4];

struct g{
    int s,e,m;
};

void update_lazy(int node, int S, int E){
    if(lazy[node]){
        if(S!=E){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        tree[node]+=(E-S+1)*lazy[node];
        lazy[node]=0;
    }
}

void update_range(int l, int r, int v, int node, int S, int E){
    update_lazy(node,S,E);
    if(E<l || r<S) return;
    if(l<=S && E<=r){
        tree[node]+=(E-S+1)*v;
        if(S!=E){
            lazy[2*node]+=v;
            lazy[2*node+1]+=v;
        }
        return;
    }
    int mid=(S+E)/2;
    update_range(l,r,v,2*node,S,mid);
    update_range(l,r,v,2*node+1,mid+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k,n,c;
    cin >> k >> n >> c;
    vector<g> a(k);
    for(g &t:a) cin >> t.s >> t.e >> t.m;

    return 0;
}