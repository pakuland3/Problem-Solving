#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; cin >> n >> m;
    vector<int> psm(n); cin >> psm[0]; 
    for(int i=1;i<n;i++){cin >> psm[i]; psm[i]+=psm[i-1];}
    for(int i=0;i<m;i++){
        int s,e; cin >> s >> e; s--; e--;
        if(s==0) cout << psm[e] << '\n';
        else cout << psm[e]-psm[s-1] << '\n';
    }
    return 0;
}