// segment tree - TLE CODE

// #include <bits/stdc++.h>
// #define MAX 1e9+1
// #define SIZE 1<<24
// typedef long long ll;
// using namespace std;

// vector<int> tree(SIZE);

// void update(int X, int V, int node, int S, int E){
//     if(S==E){
//         tree[node]=V;
//         return;
//     }
//     int MID=(S+E)/2;
//     if(X<=MID) update(X,V,2*node,S,MID);
//     else update(X,V,2*node+1,MID+1,E);
//     tree[node]=min(tree[2*node],tree[2*node+1]);
// }

// int query(int L, int R, int node, int S, int E){
//     if(R<S || E<L) return MAX;
//     if(L<=S && E<=R) return tree[node];
//     int MID=(S+E)/2;
//     return min(query(L,R,2*node,S,MID),query(L,R,2*node+1,MID+1,E));
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int n,l,a;
//     cin >> n >> l;
//     for(int i=1;i<=n;i++){
//         cin >> a;
//         update(i,a,1,1,n);
//     }
//     for(int i=1;i<=n;i++){
//         int start=max(1,i-l+1);
//         cout << query(start,i,1,1,n) << ' ';
//     }
//     return 0;
// }

// deque

