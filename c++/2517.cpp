#include <bits/stdc++.h>
#define SIZE 500001*4 // 500001
typedef long long ll;
using namespace std;

int tree[SIZE];

void update(int X, int node, int S, int E){
    if(E<X || X<S) return;
    if(S==E){
        tree[node]++;
        return;
    }
    int MID=(S+E)/2;
    update(X,2*node,S,MID);
    update(X,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int R, int node, int S, int E){
    if(R<=S) return 0;
    if(E<R) return tree[node];
    int MID=(S+E)/2;
    return query(R,2*node,S,MID)+query(R,2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    vector<int> b(a);
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        auto it=lower_bound(b.begin(),b.end(),a[i]);
        int t=it-b.begin()+1;
        update(t,1,1,n);
        cout << i+1-query(t,1,1,n) << '\n';
    }
    return 0;
}