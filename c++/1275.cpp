#include <bits/stdc++.h>
#define SIZE 1<<21
typedef long long ll;
using namespace std;

vector<ll> tree(SIZE);

void update(int X, int V, int node, int S, int E){
    if(S==E){
        tree[node]=V;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int L, int R, int node, int S, int E){
    if(R<S || E<L) return 0;
    if(L<=S && E<=R) return tree[node];
    int MID=(S+E)/2;
    return query(L,R,2*node,S,MID)+query(L,R,2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        update(i,a,1,1,n);
    }
    while(q--){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        if(y<x) swap(x,y);
        cout << query(x,y,1,1,n) << '\n';
        update(a,b,1,1,n);
    }
    return 0;
}