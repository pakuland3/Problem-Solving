#include <bits/stdc++.h>
#define SIZE 1<<21
#define MOD 1000000007
typedef long long ll;
using namespace std;

vector<ll> tree(SIZE,0);

void update(int X, int V, int node, int S, int E){
    if(S==E){
        tree[node]=(ll)V;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    tree[node]=(tree[2*node]*tree[2*node+1])%MOD;
}

ll query(int L, int R, int node, int S, int E){
    if(R<S || E<L) return 1;
    if(L<=S && E<=R) return tree[node];
    int MID=(S+E)/2;
    return (query(L,R,2*node,S,MID)*query(L,R,2*node+1,MID+1,E))%MOD;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,k,ini;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> ini;
        update(i,ini,1,1,n);
    }
    for(int i=0;i<m+k;i++){
        int a;
        ll b;
        cin >> ini >> a >> b;
        if(ini==1) update(a,b,1,1,n);
        else cout << query(a,b,1,1,n) << '\n';
    }
    return 0;
}