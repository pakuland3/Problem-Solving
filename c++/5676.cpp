#include <bits/stdc++.h>
#define SIZE 1<<21
typedef long long ll;
using namespace std;

vector<int> tree(SIZE,0);

void update(int X, int V, int node, int S, int E){
    if(S==E){
        if(V>0) tree[node]=1;
        else if(V<0) tree[node]=-1;
        else tree[node]=0;
        return;
    }
    int MID=(S+E)/2;
    if(X<=MID) update(X,V,2*node,S,MID);
    else update(X,V,2*node+1,MID+1,E);
    tree[node]=tree[2*node]*tree[2*node+1];
}

int query(int L, int R, int node, int S, int E){
    if(R<S || E<L) return 1;
    if(L<=S && E<=R) return tree[node];
    int MID=(S+E)/2;
    return query(L,R,2*node,S,MID)*query(L,R,2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    while(cin >> n >> k){
        for(int i=1;i<=n;i++){
            int a;
            cin >> a;
            update(i,a,1,1,n);
        }
        while(k--){
            char c;
            int a,b;
            cin >> c >> a >> b;
            if(c=='C') update(a,b,1,1,n);
            else{
                int ans=query(a,b,1,1,n);
                if(ans>0) cout << '+';
                else if(ans<0) cout << '-';
                else cout << 0;
            }
        }
        cout << '\n';
    }
    return 0;
}