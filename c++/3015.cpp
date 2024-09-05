#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,a,cur;
    cin >> n;
    ll res=0;
    stack<pair<int,pair<int,bool>>> st;
    while(n--){
        cin >> a;
        if(st.empty()){
            st.push({a,{1,1}});
            continue;
        }
        while(!st.empty() && st.top().first<a){
            res++;
            st.pop();
        }
        if(!st.empty()){
            if(st.top().first==a){
                cur=st.top().second.first;
                res+=(ll)(cur+!st.top().second.second);
                st.push({a,{cur+1,st.top().second.second}});
                continue;
            }
            else res++;
        }
        st.push({a,{1,st.empty()}});
    }
    cout << res;
    return 0;
}