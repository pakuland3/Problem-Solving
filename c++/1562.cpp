// good approche but wrong answer
// #include <bits/stdc++.h>
// #define MOD (int)1e8
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int n;
//     cin >> n;
//     vector<vector<vector<int>>> dp(2,vector<vector<int>> (10,vector<int> (10,0)));
//     for(int i=1;i<10;i++) dp[0][i][i]=1;
//     for(int i=1;i<n;i++){
//         for(int l=0;l<10;l++) dp[i%2][0][l]=(dp[i%2][0][l]+dp[!(i%2)][1][l])%MOD;
//         for(int j=1;j<9;j++) for(int l=0;l<10;l++) dp[i%2][j][l]=((dp[i%2][j][l]+dp[!(i%2)][j-1][l])%MOD+dp[!(i%2)][j+1][l])%MOD;
//         for(int l=0;l<10;l++) dp[i%2][9][l]=(dp[i%2][9][l]+dp[!(i%2)][8][l])%MOD;
//     }
//     int ans=0;
//     for(int i=0;i<10;i++){
//         int tmp=dp[(n-1)%2][i][0];
//         for(int j=1;j<10;j++) tmp=min(tmp,dp[(n-1)%2][i][j]);
//         ans=(ans+tmp)%MOD;
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
#define MOD (int)1e9
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("in","r",stdin);
    // int t;
    // cin >> t;
    // while(t--){
    int n;
    cin >> n;
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (10,vector<int> (1024,0)));
    for(int i=1;i<10;i++) dp[0][i][1<<i]=1;
    for(int i=1;i<n;i++) for(int j=0;j<10;j++) for(int k=1;k<1024;k++){
        if(j==0) dp[i][0][k|(1<<0)]=(dp[i][0][k|(1<<0)]+dp[i-1][1][k])%MOD;
        else if(j==9) dp[i][9][k|(1<<9)]=(dp[i][9][k|(1<<9)]+dp[i-1][8][k])%MOD;
        else dp[i][j][k|(1<<j)]=((dp[i][j][k|(1<<j)]+dp[i-1][j+1][k])%MOD+dp[i-1][j-1][k])%MOD;
    }
    int ans=0;
    for(int i=0;i<10;i++) ans=(ans+dp[n-1][i][1023])%MOD;
    cout << ans << '\n';
    // }
    return 0;
}