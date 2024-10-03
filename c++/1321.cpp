#include <bits/stdc++.h>
#define SIZE 500001*4 // 500001
typedef long long ll;
using namespace std;

ll tree[SIZE];
ll lazy[SIZE];

void update_lazy(int node, ll S, ll E){
	if(lazy[node]!=0){
		if(S!=E){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		tree[node]+=(E-S+1ll)*lazy[node];
		lazy[node]=0;
	}
}

void update_range(int L, int R, ll V, int node, ll S, ll E){
	update_lazy(node,S,E);
	if(R<S || E<L) return;
	if(L<=S && E<=R){
		tree[node]+=(E-S+1ll)*V;
        if(S!=E){
            lazy[2*node]+=V;
            lazy[2*node+1]+=V;
        }
		return;
	}
	int MID=(S+E)/2;
	update_range(L,R,V,2*node,S,MID);
	update_range(L,R,V,2*node+1,MID+1,E);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int query(ll n, int node, ll S, ll E){
	update_lazy(node,S,E);
    if(S==E) return S;
    int MID=(S+E)/2;
	if(tree[2*node]>=n) return query(n,2*node,S,MID);
    return query(n-tree[2*node],2*node+1,MID+1,E);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        update_range(i+1,i+1,t,1,1,n);
    }
    int m;
    cin >> m;
    while(m--){
        int sign;
        ll a,b;
        cin >> sign;
        if(sign==1){
            cin >> a >> b;
            update_range(a,a,b,1,1,n);
        }
        else{
            cin >> a;
            cout << query(a,1,1,n) << '\n';
        }
    }
}