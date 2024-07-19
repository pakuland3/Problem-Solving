#include <bits/stdc++.h>
#define SIZE 65536
typedef long long ll;
typedef long double ld;
using namespace std;

int tree[4*SIZE],arr[250001];

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
    if(tree[2*node]>=cnt) return query(cnt,2*node,S,MID);
    return query(cnt-tree[2*node],2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> arr[i];
        update(arr[i],1,1,0,SIZE);
    }
    ll ans=query((k+1)/2,1,0,SIZE);
    for(int i=1;i<n-k+1;i++){
        cin >> arr[k+i-1];
        update(arr[i-1],-1,1,0,SIZE);
        update(arr[k+i-1],1,1,0,SIZE);
        ans+=query((k+1)/2,1,0,SIZE);
    }
    cout << ans;
    return 0;
}