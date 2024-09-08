#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(pair<string,string> &a){
    for(int i=0;i<a.first.length();i++) if(a.first[i]<'a') a.first[i]+=32;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(1){
        getline(cin,s);
        if(s.length()==1) break;
        vector<pair<string,string>> a;
        vector<int> b;
        vector<bool> d;
        string c="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            if(s[i]==',' || s[i]=='.'){
                if('9'<c[0]){
                    a.push_back({c,c});
                    solve(a.back());
                    d.push_back(0);
                }
                else{
                    b.push_back(stoi(c));
                    d.push_back(1);
                }
                c="";
            }
            else c+=s[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int id=0,idd=0;
        for(int i=0;i<a.size()+b.size();i++){
            if(d[i]) cout << b[idd++];
            else cout << a[id++].second;
            if(i!=a.size()+b.size()-1) cout << ", ";
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}