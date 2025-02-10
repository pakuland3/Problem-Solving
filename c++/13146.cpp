#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    stack<int> st;
    ll ans=0;
    int n,t,s;
    cin >> n >> t;
    st.push(t);
    for(int i=1;i<n;i++){
        cin >> t;
        if(t<st.top()) st.push(t);
        if(t>st.top()){
            s=st.top();
            st.pop();
            while(st.size() && st.top()<t){
                ans+=st.top()-s;
                s=st.top();
                st.pop();
            }
            ans+=t-s;
            st.push(t);
        }
    }
    while(st.size()>1){
        s=st.top();
        st.pop();
        ans+=st.top()-s;
    }
    cout << ans;
    return 0;
}

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int n;
//     cin >> n;
//     while(n--) cout << rand()%20+1 << ' ';
//     return 0;
// }