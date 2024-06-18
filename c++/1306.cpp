#include <bits/stdc++.h>
#define SIZE 1<<21
typedef long long ll;
using namespace std;

vector<int> tree(SIZE);

void update(int X, int V, int node, int S, int E){
    if(S==E){
        tree[node]=V;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int L, int R, int node, int S, int E){
    if(R<S || E<L) return 0;
    if(L<=S && E<=R) return tree[node];
    int MID=(S+E)/2;
    return max(query(L,R,2*node,S,MID),query(L,R,2*node+1,MID+1,E));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,ini;
    cin >> n >> m;
    for(int i=1;i<=n;i++){cin >> ini; update(i,ini,1,1,n);}
    for(int i=m;i<=n-m+1;i++) cout << query(i-,i+m,) << ' ';
    return 0;
}