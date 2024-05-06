#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
    string a;
    int maxi=0,ind;
    getline(cin,a);
    vector<int> cnt(26,0),maxcnt(255,0);
    for(int i=0;i<a.length();i++) if(a[i]!=' '){
        cnt[a[i]-'a']++;
        if(maxi<=cnt[a[i]-'a']){
            maxi=cnt[a[i]-'a'];
            maxcnt[maxi]++;
            ind=i;
        }
    }
    if(maxcnt[maxi]>1) cout << "?\n";
    else cout << a[ind] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    cin.ignore();
    while(t--) solve();
    return 0;
}