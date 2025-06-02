#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    set<string> s;
    vector<string> ans;
    while(n--){
        int cnt[26]={0,};
        string a,b("");
        cin >> a;
        for(int i=0;i<a.length();i++) cnt[a[i]-'a']++;
        for(int i=0;i<26;i++) b+=cnt[i]+'0';
        if(s.find(b)==s.end()){
            s.insert(b);
            ans.push_back(a);
        }
    }
    for(auto t:ans) cout << t << '\n';
    return 0;
}