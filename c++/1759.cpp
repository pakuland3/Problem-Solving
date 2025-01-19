#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> ans;
vector<char> a;
int l,c;

void solve(int len, int idx, string &t, int v, int cc){
    if(len==l){
        if(v && cc>1) ans.push_back(t);
        return;
    }
    for(int i=idx+1;i<c;i++){
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u'){
            t+=a[i];
            solve(len+1,i,t,1,cc);
            t.erase(t.length()-1);
        }
        else{
            t+=a[i];
            solve(len+1,i,t,v,cc+1);
            t.erase(t.length()-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> l >> c;
    a.resize(c);
    for(char &t:a) cin >> t;
    sort(a.begin(),a.end());
    string t("");
    solve(0,-1,t,0,0);
    sort(ans.begin(),ans.end());
    for(auto &s:ans) cout << s << '\n';
    return 0;
}