#include <bits/stdc++.h>
using namespace std;

bool ck(string &a, int l){
    if(l==1) return 1;
    for(int i=0;i<l/2;i++) if(a[i]==a[l-(i+1)]) return 0;
    a=a.substr(0,(l-1)/2);
    return ck(a,(l-1)/2);
}

void solve(){
    string s;
    cin >> s;
    int l=s.length();
    if(ck(s,l)) cout << "YES\n";
    else cout << "NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}