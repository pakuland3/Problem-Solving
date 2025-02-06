#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll p,n,s;
        int res=0;
        cin >> p >> n;
        stack<ll> st;
        int d=0;
        for(int i=0;i<n;i++){
            cin >> s;
            while(st.size() && p<=s){
                p+=st.top();
                res++;
                st.pop();
            }
            if(p<=s) d=1;
            st.push(s);
        }
        if(d) cout << "NIE\n";
        else cout << res+1 << '\n';
    }
    return 0;
}