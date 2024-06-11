#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k,n;
    cin >> k >> n;
    vector<string> a(k);
    for(auto &s:a) cin >> s;
    sort(a.begin(),a.end(),[](string l, string r)->bool{
        if(l.length()==r.length()) return stoull(l)>stoull(r);
        return l.length()>r.length();
    });
    for(int i=0;i<n-k;i++) a.push_back(a[0]);
    sort(a.begin(),a.end(),[](string l, string r)->bool{
        return stoull(l+r)>stoull(r+l);
    });
    for(auto &s:a) cout << s;
    return 0;
}