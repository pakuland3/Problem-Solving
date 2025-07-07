#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    int idx[500001];
    cin >> n >> q;
    for(int i=1;i<=n;i++) idx[i]=i;
    vector<set<int>> A(n+1);
    for(int i=1;i<=n;i++){
        int s,t;
        cin >> t;
        for(int j=0;j<t;j++) cin >> s,A[i].insert(s);
    }
    while(q--){
        int Q,a,b,ai,bi;
        cin >> Q >> a;
        ai=idx[a];
        if(Q==1){
            cin >> b;
            bi=idx[b];
            if(A[ai].size()>A[bi].size()){
                for(auto it=A[bi].begin();it!=A[bi].end();it++) A[ai].insert(*it);
                A[bi].clear();
            }
            else{
                for(auto it=A[ai].begin();it!=A[ai].end();it++) A[bi].insert(*it);
                A[ai].clear();
                swap(idx[a],idx[b]);
            }
        }
        else cout << A[ai].size() << '\n';
    }
    return 0;
}