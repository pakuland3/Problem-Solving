#include <bits/stdc++.h>
#define INF 10000001
typedef long long ll;
using namespace std;

int n,m;
int dp[101][101],r[101][101];

void solve(stack<int> &st, int a, int b){
    if(r[a][b]!=a){
        solve(st,r[a][b],b);
        solve(st,a,r[a][b]);
        return;
    }
    st.push(a);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill(dp[0],dp[101],INF);
    cin >> n >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(dp[a][b]>c){
            dp[a][b]=c;
            r[a][b]=a;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        r[i][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dp[j][k]>dp[j][i]+dp[i][k]){
                    dp[j][k]=dp[j][i]+dp[i][k];
                    r[j][k]=i;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << (dp[i][j]!=INF?dp[i][j]:0) << ' ';
        cout << '\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j || dp[i][j]==INF) cout << 0;
            else{
                stack<int> st;
                solve(st,i,j);
                if(st.top()!=i) st.push(i);
                cout << st.size()+1 << ' ';
                while(!st.empty()){
                    cout << st.top() << ' ';
                    st.pop();
                }
                cout << j;
            }
            cout << '\n';
        }
    }
    return 0;
}