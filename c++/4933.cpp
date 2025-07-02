#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

void solve(unordered_map<char,pair<char,char>> &c){
    vector<char> s;
    string t;
    while(cin >> t && t[0]!='e') s.push_back(t[0]);
    reverse(s.begin(),s.end());
    stack<pair<char,int>> st;
    for(int i=0;i<s.size();i++){
        if(!st.empty()){
            if(st.top().se) c[st.top().fi].fi=s[i],st.pop();
            else c[st.top().fi].se=s[i],st.top().se=1;
        }
        if(s[i]!='n') st.push({s[i],0}),c[s[i]]={0,0};
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        unordered_map<char,pair<char,char>> a,b;
        solve(a);
        solve(b);
        int flag=a.size()!=b.size();
        for(auto it=a.begin();!flag && it!=a.end();it++){
            if(b.find(it->fi)==b.end()){
                flag=1;
                break;
            }
            if(!((it->se.fi==b[it->fi].fi || it->se.fi==b[it->fi].se) && (it->se.se==b[it->fi].fi || it->se.se==b[it->fi].se))) flag=1;
        }
        cout << (flag?"false":"true") << '\n';
    }
    return 0;
}