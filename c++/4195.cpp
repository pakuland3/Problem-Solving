// #include <bits/stdc++.h>
// using namespace std;

// string getParent(string a, map<string, pair<string, int>> &m){
//     if(a==m[a].first) return a;
//     return m[a].first=getParent(m[a].first,m);
// }

// void unionParent(string a, string b, map<string, pair<string, int>> &m){
//     a=getParent(a,m);
//     b=getParent(b,m);
//     if(a==b) return;
//     m[b].second+=m[a].second;
//     m[a].first=b;
// }

// void solve(){
//     map<string, pair<string, int>> m;
//     string a,b;
//     int f,l[2];
//     cin >> f;
//     for(int i=0;i<f;i++){
//         cin >> a >> b;
//         if(m.find(a)==m.end()) m.insert({a,{a,1}});
//         if(m.find(b)==m.end()) m.insert({b,{b,1}});
//         a=getParent(a,m);
//         b=getParent(b,m);
//         if(a!=b) unionParent(a,b,m);
//         cout << max(m[a].second,m[b].second) << '\n';
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int t; cin >> t; while(t--) solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

string getParent(string a, unordered_map<string, pair<string, int>> &m){
    if(a==m[a].first) return a;
    return m[a].first=getParent(m[a].first,m);
}

void unionParent(string a, string b, unordered_map<string, pair<string, int>> &m){
    a=getParent(a,m);
    b=getParent(b,m);
    if(a==b) return;
    m[b].second+=m[a].second;
    m[a].first=b;
}

void solve(){
    unordered_map<string, pair<string, int>> m;
    string a,b;
    int f,l[2];
    cin >> f;
    for(int i=0;i<f;i++){
        cin >> a >> b;
        if(m.find(a)==m.end()) m.insert({a,{a,1}});
        if(m.find(b)==m.end()) m.insert({b,{b,1}});
        a=getParent(a,m);
        b=getParent(b,m);
        if(a!=b) unionParent(a,b,m);
        cout << max(m[a].second,m[b].second) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while(t--) solve();
    return 0;
}