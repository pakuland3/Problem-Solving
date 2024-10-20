#include <bits/stdc++.h>
#define SIZE 100001
typedef long long ll;
using namespace std;

int dp[SIZE];
int r[SIZE];
bool vis[SIZE];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    bool break_point=1;
    cin >> n >> k;
    dp[n]=0;
    r[n]=n;
    vis[n]=1;
    queue<int> q;
    q.push(n);
    while(!q.empty() && break_point){
        int x=q.front();
        q.pop();
        for(int nx:{x-1,x+1,2*x}){
            if(100000<nx || nx<0) continue;
            if(vis[nx]) continue;
            dp[nx]=dp[x]+1;
            r[nx]=x;
            vis[nx]=1;
            if(nx==k){
                break_point=0;
                break;
            }
            q.push(nx);
        }
    }
    stack<int> st;
    st.push(k);
    while(k!=n){
        k=r[k];
        st.push(k);
    }
    cout << st.size()-1 << '\n';
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}