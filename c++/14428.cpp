#include <bits/stdc++.h>
#define SIZE 1<<21
#define MAX (int)2e9
typedef long long ll;
using namespace std;

vector<int> tree(SIZE,MAX),idx(SIZE);

void update(int X, int V, int node, int S, int E){
    if(S==E){
        tree[node]=V;
        idx[node]=X;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    if(tree[2*node+1]<tree[2*node]){
        tree[node]=tree[2*node+1];
        idx[node]=idx[2*node+1];
    }
    else{
        tree[node]=tree[2*node];
        idx[node]=idx[2*node];
    }
}

pair<int,int> getMini(int L, int R, int node, int S, int E){
    if(R<S || E<L) return {MAX,-1};
    if(L<=S && E<=R) return {tree[node],idx[node]};
    int MID=(S+E)/2;
    pair<int,int> p1=getMini(L,R,2*node,S,MID),p2=getMini(L,R,2*node+1,MID+1,E);
    if(p1.first>p2.first) return p2;
    else return p1;
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
        else cout << getMini(a,b,1,1,n).second << '\n';
    }
    return 0;
}