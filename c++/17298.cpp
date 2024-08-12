#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int n,a;
int b[1000000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(b,-1,sizeof(b));
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        cin >> a;
        while(!st.empty()){
            if(a<=st.top().fi) break;
            b[st.top().se]=a;
            st.pop();
        }
        st.push({a,i});
    }
    for(int i=0;i<n;i++) cout << b[i] << ' ';
    return 0;
}