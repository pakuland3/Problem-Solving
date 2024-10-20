#include <bits/stdc++.h>
#define SIZE 200001
#define MOD 1000000007
typedef long long ll;
using namespace std;

int n;
ll k;

struct Node{
    ll tree,cnt;
};

ll tree[SIZE*4];
ll cnt[SIZE*4];

void update(int X, int node, int S, int E){
    if(E<X || X<S) return;
    if(S==E){
        tree[node]=tree[node]+X;
        cnt[node]++;
        return;
    }
    int MID=(S+E)/2;
    update(X,2*node,S,MID);
    update(X,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
    cnt[node]=cnt[2*node]+cnt[2*node+1];
}

Node query(int L, int R, int node, int S, int E){
    if(R<L || SIZE-1<R) return {0,0};
    if(R<S || E<L) return {0,0};
    if(L<=S && E<=R) return {tree[node],cnt[node]};
    int MID=(S+E)/2;
    Node left=query(L,R,2*node,S,MID);
    Node right=query(L,R,2*node+1,MID+1,E);
    return {left.tree+right.tree,left.cnt+right.cnt};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    update(k,1,0,SIZE-1);
    ll res=k;
    cin >> k;
    update(k,1,0,SIZE-1);
    res=abs(k-res);
    for(int i=2;i<n;i++){
        cin >> k;
        update(k,1,0,SIZE-1);
        Node l=query(0,k-1,1,0,SIZE-1);
        Node r=query(k+1,SIZE-1,1,0,SIZE-1);
        res=(res*((r.tree-r.cnt*k)%MOD+(k*l.cnt-l.tree)%MOD)%MOD)%MOD;
    }
    cout << res;
    return 0;
}