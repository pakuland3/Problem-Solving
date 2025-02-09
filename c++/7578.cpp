#include <bits/stdc++.h>
#define SIZE 500001
typedef long long ll;
using namespace std;

ll tree[SIZE*4];

void update(int x, int node, int s, int e){
    if(e<x || x<s) return;
    if(s==e){
        tree[node]++;
        return;
    }
    int mid=(s+e)/2;
    update(x,2*node,s,mid);
    update(x,2*node+1,mid+1,e);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(int x, int node, int s, int e){
    if(e<x) return 0;
    if(x<=s) return tree[node];
    int mid=(s+e)/2;
    return query(x,2*node,s,mid)+query(x,2*node+1,mid+1,e);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;    
    unordered_map<int,int> um;
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        um[t]=i;
    }
    ll res=0;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        res+=query(um[t],1,1,n);
        update(um[t],1,1,n);
    }
    cout << res;
    return 0;
}