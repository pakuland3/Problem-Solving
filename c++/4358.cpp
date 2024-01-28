#include <bits/stdc++.h>
using namespace std;

string s;
map<string, int> m;
double ansratio;
int cnt=0;

int main(){
    cout << fixed;
    cout.precision(4);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(1){
        getline(cin,s);
        if(s=="") break;
        if(m.find(s)!=m.end()){
            m[s]++;
        }
        else{
            m.insert({s,1});
        }
        cnt++;
    }
    for(auto it=m.begin();it!=m.end();it++){
        ansratio=it->second*100/(double)cnt;
        cout << it->first << ' ' << ansratio << '\n';
    }
}