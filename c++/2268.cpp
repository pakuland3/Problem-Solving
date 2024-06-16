#include <bits/stdc++.h>
#define SIZE 1<<21
typedef long long ll;
using namespace std;

vector<ll> tree(SIZE,0);

void update(int X, ll V, int node, int S, int E){
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
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a) update(b,c,1,1,n);
        else{
            if(b<c) cout << query(b,c,1,1,n) << '\n';
            else cout << query(c,b,1,1,n) << '\n';
        }
    }
    return 0;
}