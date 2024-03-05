#include <bits/stdc++.h>
using namespace std;

struct ip{
    int iint;
    char ichar;
};
int t;

void solve(){
    deque<int> dq;
    ip tmp;
    int n;
    string s;
    bool b=true,e=false;
    cin >> s >> n;
    if(n!=0){ 
        for(int i=0;i<2*n+1;i++){
            if((i+1)%2!=0) cin >> tmp.ichar;
            else{
                cin >> tmp.iint; if(n!=0) dq.push_back(tmp.iint);
            }
        }
    }
    else for(int i=0;i<2;i++) cin >> tmp.ichar;
    for(int i=0;i<s.length();i++){
        if(e) break;
        if(s[i]=='D'){
            if(dq.empty()) e=true;
            else if(b) dq.pop_front();
            else dq.pop_back();
        }
        else b=!b;
    }
    if(e) cout << "error";
    else{
        cout << '[';
        if(b) while(!dq.empty()){
            if(dq.size()!=1) cout << dq.front() << ',';
            else cout << dq.front();
            dq.pop_front();
        }
        else while(!dq.empty()){
            if(dq.size()!=1) cout << dq.back() << ',';
            else cout << dq.back();
            dq.pop_back();
        }
        cout << ']';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t; while(t--) solve();
    return 0;
}