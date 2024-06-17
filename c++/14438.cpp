#include <bits/stdc++.h>
#define SIZE 1<<21
#define MAX (int)2e9
typedef long long ll;
using namespace std;

vector<int> tree(SIZE,MAX);

void update(int X, int V, int node, int S, int E){
    if(S==E){
        tree[node]=V;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    if(tree[2*node+1]<tree[2*node]) tree[node]=tree[2*node+1];
    else tree[node]=tree[2*node];
}

int getMini(int L, int R, int node, int S, int E){
    if(R<S || E<L) return MAX;
    if(L<=S && E<=R) return tree[node];
    int MID=(S+E)/2;
    return min(getMini(L,R,2*node,S,MID),getMini(L,R,2*node+1,MID+1,E));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ini,m;
    cin >> n;
    for(int i=1;i<=n;i++){cin >> ini; update(i,ini,1,1,n);}
    cin >> m;
    while(m--){
        int a,b;
        cin >> ini >> a >> b;
        if(ini==1) update(a,b,1,1,n);
        else cout << getMini(a,b,1,1,n) << '\n';
    }
    return 0;
}