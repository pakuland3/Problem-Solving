#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    stack<int> st;
    int n,reg,tmp;
    cin >> n;
    pair<string,int> a[1001];
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        if(a[i].first[0]=='I' || (a[i].first[0]=='P' && a[i].first[1]=='U')) cin >> a[i].second;
    }
    for(int i=0;i<n;i++){
        if(a[i].first[0]=='P' && a[i].first[1]=='U') st.push(a[i].second);
        else if(a[i].first[0]=='S'){
            reg=st.top();
            st.pop();
        }
        else if(a[i].first[0]=='L') st.push(reg);
        else if(a[i].first[0]=='P' && a[i].first[1]=='L'){
            tmp=st.top();
            st.pop();
            tmp+=st.top();
            st.pop();
            st.push(tmp);
        }
        else if(a[i].first[0]=='T'){
            tmp=st.top();
            st.pop();
            tmp*=st.top();
            st.pop();
            st.push(tmp);
        }
        else if(a[i].first[0]=='I'){
            tmp=st.top();
            st.pop();
            if(tmp==0) i=a[i].second-1;
        }
        else if(a[i].first[0]=='D') break;
    }
    cout << st.top();
    return 0;
}