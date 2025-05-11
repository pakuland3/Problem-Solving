#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    map<string,int> m;
    for(int i=0;i<n;i++){
        string t;
        cin >> t;
        m[t]=i;
    }
    string a,b("");
    cin >> a;
    stack<int> st;
    for(int i=0;i<a.size();i++){
        b+=a[i];
        if(m.find(b)!=m.end()){
            st.push(m[b]);
            b="";
        }
    }
    int res=0;
    int mul=1;
    while(!st.empty()){
        res+=st.top()*mul;
        st.pop();
        mul*=n;
    }
    cout << res;
    return 0;
}