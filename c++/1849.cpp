// #include <bits/stdc++.h>
// #define SIZE 100001*4 // 100001
// typedef long long ll;
// using namespace std;

// ll tree[SIZE];
// ll lazy[SIZE];
// int ans[SIZE/4];

// void update_lazy(int node, ll S, ll E){
//     if(lazy[node]!=0){
//         tree[node]+=(E-S+1)*lazy[node];
//         if(S!=E){
//             lazy[2*node]+=lazy[node];
//             lazy[2*node+1]+=lazy[node];
//         }
//         lazy[node]=0;
//     }
// }

// void update_range(int L, int R, ll V, int node, ll S, ll E){
//     update_lazy(node,S,E);
//     if(R<S || E<L) return;
//     if(L<=S && E<=R){
//         tree[node]+=V*(E-S+1);
//         if(S!=E){
//             lazy[2*node]+=V;
//             lazy[2*node+1]+=V;
//         }
//         return;
//     }
//     int MID=(S+E)/2;
//     update_range(L,R,V,2*node,S,MID);
//     update_range(L,R,V,2*node+1,MID+1,E);
//     tree[node]=tree[2*node]+tree[2*node+1];
// }

// int query(ll V, int node, int S, int E){
//     if(S==E) return S;
//     int MID=(S+E)/2;
//     update_lazy(2*node,S,MID);
//     update_lazy(2*node+1,MID+1,E);
//     if(tree[2*node]>V) return query(V,2*node,S,MID);
//     else return query(V-tree[2*node],2*node+1,MID+1,E);
// }


// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int n;
//     cin >> n;
//     update_range(1,n,1,1,1,n);
//     for(int i=1;i<=n;i++){
//         ll back;
//         cin >> back;
//         int idx=query(back,1,1,n);
//         ans[idx]=i;
//         update_range(idx,idx,-1,1,1,n);
//     }
//     for(int i=1;i<=n;i++) cout << ans[i] << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
#define SIZE 100001*4 // 100001
typedef long long ll;
using namespace std;

int tree[SIZE];
int ans[SIZE/4];

void update(int X, int V, int node, int S, int E){
    if(E<X || X<S) return;
    if(S==E){
        tree[node]+=V;
        return;
    }
    int MID=(S+E)/2;
    update(X,V,2*node,S,MID);
    update(X,V,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int V, int node, int S, int E){
    if(S==E) return S;
    int MID=(S+E)/2;
    if(tree[2*node]>V) return query(V,2*node,S,MID);
    return query(V-tree[2*node],2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) update(i,1,1,1,n);
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        int q=query(a,1,1,n);
        ans[q]=i;
        update(q,-1,1,1,n);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << '\n';
    return 0;
}