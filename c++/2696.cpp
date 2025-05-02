#include <bits/stdc++.h>
#define SIZE (int)1e4
typedef long long ll;
using namespace std;

int tree[SIZE*4];

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

int query(int x, int node, int s, int e){
    if(s==e) return s;
    int mid=(s+e)/2;
    if(tree[2*node]>x) return query(x,2*node,s,mid);
    return query(x-tree[2*node],2*node+1,mid+1,e);
}

void solve1(){
    int n;
    cin >> n;
    memset(tree,0,sizeof(tree));
    vector<int> a(n);
    for(int &t:a) cin >> t;
    vector<int> b(a),c(n);
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++) c[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    cout << n/2+1 << '\n';
    for(int i=0;i<n;i++){
        update(c[i],1,0,n-1);
        if(i%2==0) cout << b[query(i/2,1,0,n-1)] << ' ';
    }
    cout << '\n';
}

void solve2(){
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> npq;
    priority_queue<int,vector<int>> xpq;
    cout << n/2+1 << '\n';
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if(i&1){
            if(!xpq.empty() && xpq.top()>t){
                xpq.push(t);
                npq.push(xpq.top());
                xpq.pop();
            }
            else npq.push(t);
        }
        else{
            if(!npq.empty() && npq.top()<t){
                npq.push(t);
                xpq.push(npq.top());
                npq.pop();
            }
            else xpq.push(t);
            cout << xpq.top() << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve2();
//        solve1();
    }
    return 0;
}