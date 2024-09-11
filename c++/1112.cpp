#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll x,b,q;
    cin >> x >> b;
    bool c=0;
    if(b>0 && x<0){
        c=1;
        x*=-1;
    }
    stack<int> st;
    while(x){
        q=x/b;
        if(x!=q*b && x<0) q++;
        st.push(x-q*b);
        x=q;
    }
    if(st.empty()){ cout << 0; return 0; }
    if(c) cout << '-';
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}