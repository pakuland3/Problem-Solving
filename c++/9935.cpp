#include <bits/stdc++.h>
using namespace std;

string s;
string t;
deque<char> dq;
int p=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> t;
    for(int i=0;i<s.length();i++) dq.push_back(s[i]);
    dq.push_back('/');
    while(dq.size()>1){
        bool b=false;
        int cnt=dq.size();
        p=0;
        for(int i=0;i<cnt;i++){
            char c=dq.front();
            dq.pop_front();
        }
        if(!b) break;
    }
    if(dq.empty()) cout << "FRULA";
    int cnt=dq.size();
    for(int i=0;i<cnt;i++){
        cout << dq.front(); dq.pop_front();
    }
    return 0;
}