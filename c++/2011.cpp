#include <bits/stdc++.h>
#define MOD (int)1e6
typedef long long ll;
using namespace std;

bool ed=0;
unordered_map<string, int> um;

int solve(string &s){
    if(ed) return 0;
    if(s[0]=='0') ed=1;
    if(um.find(s)!=um.end()) return um[s];
    if(s.length()==1) return um[s]=1;
    string t(s); t.erase(0,1); string c(t); c.erase(0,1);
    if(s.length()==2){
        if(10*(s[0]-'0')+s[1]-'0'<27){
            if(s[1]!='0') return um[s]=2;
            return um[s]=1;
        }
        if(s[1]=='0') ed=1;
        return um[s]=1;
    }
    if(s[1]!='0'){
        if(10*(s[0]-'0')+s[1]-'0'<27 && s[2]!='0') return um[s]=(solve(c)+solve(t))%MOD;
        return um[s]=solve(t);
    }
    if(s[0]<'3' && s[2]!='0') return um[s]=solve(c);
    ed=1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a;
    cin >> a;
    solve(a);
    if(ed) cout << 0;
    else cout << um[a];
    return 0;
}