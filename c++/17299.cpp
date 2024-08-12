#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int n,cnt[1000001];
int a,b[1000000],c[1000000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(c,-1,sizeof(c));
    for(int i=0;i<n;i++){
        cin >> b[i];
        cnt[b[i]]++;
    }
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        while(!st.empty()){
            if(cnt[b[i]]<=st.top().fi) break;
            c[st.top().se]=b[i];
            st.pop();
        }
        st.push({cnt[b[i]],i});
    }
    for(int i=0;i<n;i++) cout << c[i] << ' ';
    return 0;
}