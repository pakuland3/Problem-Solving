#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        string n;
        cin >> n;
        int sum=0;
        for(int i=0;i<n.length();i++) sum+=n[i]-'0';
        if(sum%9==0) cout << "YES\n";
        else cout << "NO\n";
    }
}