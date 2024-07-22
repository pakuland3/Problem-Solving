#include <bits/stdc++.h>
#define SIZE 1000000
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
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int cnt, int node, int S, int E){
    if(S==E) return S;
    int MID=(S+E)/2;
    if(tree[2*node]>=cnt) return query(cnt,2*node,S,MID);
    return query(cnt-tree[2*node],2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int a,b,c;
        cin >> a;
        if(a==1){
            cin >> b;
            int ans=query(b,1,1,SIZE);
            cout << ans << '\n';
            update(ans,-1,1,1,SIZE);
        }
        else{
            cin >> b >> c;
            update(b,c,1,1,SIZE);
        }
    }
    return 0;
}