#include <bits/stdc++.h>
#define SIZE 1<<21
#define MAX (int)2e9
typedef long long ll;
using namespace std;

vector<int> tree(SIZE,MAX);
vector<int> idx(SIZE,0);

void update(int X, int V, int node, int S, int E){
    if(S==E){
        tree[node]=V;
        idx[node]=X;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    if(tree[2*node]<tree[2*node+1]){
        tree[node]=tree[2*node];
        idx[node]=idx[2*node];
    }
    else{
        tree[node]=tree[2*node+1];
        if(tree[2*node]!=tree[2*node+1]) idx[node]=idx[2*node+1];
        else idx[node]=idx[2*node];
    }
}

int getMini(){
    return idx[1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ini,m;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ini;
        update(i,ini,1,1,n);
    }
    cin >> m;
    while(m--){
        cin >> ini;
        int i,v;
        if(ini==2) cout << getMini() << '\n';
        else{cin >> i >> v; update(i,v,1,1,n);}
    }
    return 0;
}