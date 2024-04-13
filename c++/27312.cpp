#include <bits/stdc++.h>
using namespace std;

int m,n,q,inn;

int main(){
    cin >> m >> n >> q;
    vector<int> maxi(n);
    for(int i=0;i<n;i++) cin >> maxi[i];
    vector<int> ans;
    for(int i=0;i<q;i++){
        if(i<m) cout << "? " << i+1 << ' ' << i+1 << endl;
        else{cout << "? " << 1 << ' ' << 1 << endl;cin >> inn;continue;}
        cin >> inn;
        if(inn>1) inn--;
        else inn++;
        ans.push_back(inn);
    }
    cout << "! ";
    for(int o:ans) cout << o << ' ';
    if(ans.size()!=n) for(int i=ans.size();i<=n;i++){
        cout << "1 ";
    }
    cout << endl;
    return 0;
}