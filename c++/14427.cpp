#include <bits/stdc++.h>
#define SIZE 1<<21
typedef long long ll;
using namespace std;

vector<ll> tree(SIZE,0);

void update(int X, ll V, int node, int S, int E){
    if(S==E){
        tree[X]=V;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}

int getMin(){
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,tmp;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> tmp;
        update(i,tmp,1,1,n);
    }
    
    return 0;
}