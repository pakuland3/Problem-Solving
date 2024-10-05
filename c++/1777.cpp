#include <bits/stdc++.h>
#define SIZE 100001*4 // 100001
typedef long long ll;
using namespace std;

int tree[SIZE];
int ans[SIZE/4];

void update(int X, int V, int node, int S, int E){
    if(E<X || X<S) return;
    if(S==E){
        tree[node]+=V;
        return;
    }
    int MID=(S+E)/2;
    update(X,V,2*node,S,MID);
    update(X,V,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int V, int node, int S, int E){
    if(S==E) return S;
    int MID=(S+E)/2;
    if(tree[2*node+1]>V) return query(V,2*node+1,MID+1,E);
    return query(V-tree[2*node+1],2*node,S,MID);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) update(i,1,1,1,n);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n;i>0;i--){
        int q=query(a[i],1,1,n);
        ans[q]=i;
        update(q,-1,1,1,n);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
    return 0;
}