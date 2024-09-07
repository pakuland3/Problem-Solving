#include <bits/stdc++.h>
#define MAX 1e9
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v,e;
    cin >> v >> e;
    int dp[400][400];
    int ans=MAX;
    for(int i=0;i<v;i++) for(int j=0;j<v;j++) dp[i][j]=MAX;
    for(int i=0;i<v;i++) dp[i][i]=0;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        dp[--a][--b]=c;
    }
    for(int i=0;i<v;i++) for(int j=0;j<v;j++) for(int k=0;k<v;k++) dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
    for(int i=0;i<v;i++) for(int j=0;j<v;j++) if(i!=j) ans=min(ans,dp[i][j]+dp[j][i]);
    cout << (ans==MAX?-1:ans);
    return 0;
}