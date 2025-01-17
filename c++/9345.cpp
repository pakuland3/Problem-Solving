#include <bits/stdc++.h>
#define fi first
#define se second
#define SIZE 100001
typedef long long ll;
using namespace std;

int mtree[SIZE*4],ntree[SIZE*4];
int idx[SIZE];

void update(int x, int v, int node, int s, int e){
    if(x<s || e<x) return;
    if(s==e){
        mtree[node]=v;
        ntree[node]=v;
        return;
    }
    int mid=(s+e)/2;
    update(x,v,2*node,s,mid);
    update(x,v,2*node+1,mid+1,e);
    mtree[node]=max(mtree[2*node],mtree[2*node+1]);
    ntree[node]=min(ntree[2*node],ntree[2*node+1]);
}

pair<int,int> query(int l, int r, int node, int s, int e){
    if(r<s || e<l) return {SIZE,-1};
    if(l<=s && e<=r) return {ntree[node],mtree[node]};
    int mid=(s+e)/2;
    pair<int,int> ll=query(l,r,2*node,s,mid);
    pair<int,int> rr=query(l,r,2*node+1,mid+1,e);
    return {min(ll.fi,rr.fi),max(ll.se,rr.se)};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int 아진짜등차수열감다죽었네;
    cin >> 아진짜등차수열감다죽었네;
    while(아진짜등차수열감다죽었네--){
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            update(i,i,1,0,n-1);
            idx[i]=i;
        }
        while(k--){
            int q,a,b;
            cin >> q >> a >> b;
            if(q){
                pair<int,int> qq=query(a,b,1,0,n-1);
                cout << ((qq.fi==a && qq.se==b)?"YES":"NO") << '\n';
            }
            else{
                swap(idx[a],idx[b]);
                update(a,idx[a],1,0,n-1);
                update(b,idx[b],1,0,n-1);
            }
        }
    }
    return 0;
}