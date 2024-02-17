#include <bits/stdc++.h>
using namespace std;

string s;
int cnt=0;
vector<int> ans;
bool f=true;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){ans.push_back(cnt);cnt=0;}
        else cnt++;
        if(i==s.length()-1) ans.push_back(cnt);
    }
    for(int i=0;i<ans.size();i++) if(ans[i]%2!=0){f=false;}
    if(!f){cout << -1;return 0;}
    for(int i=0;i<ans.size();i++){
        if(ans[i]%4==0) for(int j=0;j<ans[i]/4;j++){cout << "AAAA";}
        else{
            for(int j=0;j<ans[i]/4;j++){cout << "AAAA";}
            cout << "BB";
        }
        if(i!=ans.size()-1) cout << '.';
    }
}