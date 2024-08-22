#include <bits/stdc++.h>
#define SIZE 1 << 23
typedef long long ll;
using namespace std;

int n,m,q,L,R,k;
int tree[SIZE],lazy[SIZE];
bool islazy[SIZE];

void update_lazy(int node, int S, int E){
    if(islazy[node]){
        if((E-S+1)%2==1) tree[node]^=lazy[node];
        for(int a:{0,1}){
            if(islazy[2*node+a]) lazy[2*node+a]^=lazy[node];
            else{
                lazy[2*node+a]=lazy[node];
                islazy[2*node+a]=1;
            }
        }
        islazy[node]=0;
    }
}

void update_range(int L, int R, int node, int S, int E){
    update_lazy(node,S,E);
    if(R<S || E<L) return;
    if(L<=S && E<=R){
        if((E-S+1)%2==1) tree[node]^=k;
        if(S!=E){
            for(int a:{0,1}){
                if(islazy[2*node+a]) lazy[2*node+a]^=k;
                else{
                    lazy[2*node+a]=k;
                    islazy[2*node+a]=1;
                }
            }
        }
        return;
    }
    int MID=(S+E)/2;
    update_range(L,R,2*node,S,MID);
    update_range(L,R,2*node+1,MID+1,E);
    tree[node]=tree[2*node]^tree[2*node+1];
}

int query(int L, int R, int node, int S, int E){
    update_lazy(node,S,E);
    if(R<S || E<L) return 0;
    if(L<=S && E<=R) return tree[node];
    int MID=(S+E)/2;
    return query(L,R,2*node,1,MID)^query(L,R,2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("r","out",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> k;
        update_range(i,i,1,1,n);
    }
    cin >> m;
    while(m--){
        cin >> q >> L >> R;
        L++; R++;
        if(q==1){
            cin >> k;
            update_range(L,R,1,1,n);
        }
        else cout << query(L,R,1,1,n) << '\n';
    }
    return 0;
}