#include <bits/stdc++.h>
#define SIZE 65536
typedef long long ll;
typedef long double ld;
using namespace std;

int tree[4*SIZE];

void update(int X, int V, int node, int S, int E){
    if(S==E){
        tree[node]+=V;
        return;
    }
    int MID=(S+E)/2;
    if(X>MID) update(X,V,2*node+1,MID+1,E);
    else update(X,V,2*node,S,MID);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int cnt, int node, int S, int E){
    if(S==E) return S;
    int MID=(S+E)/2;
    if(tree[2*node+1]>cnt) return query(cnt,2*node+1,S,E);
    return query(cnt,2*node,S,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,a;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> a;
        update(a,1,1,1,SIZE);
    }
    ll ans=query((k+1)/2,1,1,SIZE);
    for(int i=1;i<n+1-k;i++){
        cin >> a;
        update(a,-1,1,1,SIZE);
    }
    return 0;
}