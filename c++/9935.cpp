#include <bits/stdc++.h>
using namespace std;

deque<char> dq;
string s,t;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> t;
    char l=t[t.length()-1];
    for(int i=0;i<s.length();i++){
        if(s[i]==l){
            if(dq.size()<t.length()-1){dq.push_back(s[i]);continue;}
            stack<char> tmp;
            tmp.push(s[i]);
            for(int i=1;i<t.length();i++){
                if(dq.back()!=t[t.length()-(i+1)]) break;
                tmp.push(dq.back()); dq.pop_back();
            }
            if(tmp.size()!=t.length()) while(!tmp.empty()){
                dq.push_back(tmp.top());
                tmp.pop();
            }
        }
        else dq.push_back(s[i]);
    }
    if(dq.empty()) cout << "FRULA";
    while(!dq.empty()){
        cout << dq.front(); dq.pop_front();
    }
    return 0;
}