#include <bits/stdc++.h>
using namespace std;

int dp[16][16][3];  //0 -> horizontal
bool graph[16][16]; //1 -> vertical
                    //2 -> diagonal
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    memset(dp,0,sizeof(dp)); dp[0][1][0]=1;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> graph[i][j];
    for(int i=2;i<n;i++) if(!graph[0][i] && !graph[0][i-1] && !graph[0][i-2]){dp[0][i][0]=dp[0][i-1][0];}
    for(int i=1;i<n;i++) for(int j=2;j<n;j++){
        if(graph[i][j]) continue;
        if(!graph[i][j-1] && !graph[i][j-2]){
            dp[i][j][0]+=dp[i][j-1][0];
            if(!graph[i-1][j-1] && !graph[i-1][j-2]) dp[i][j][0]+=dp[i][j-1][2];
        }
        if(!graph[i][j-1] && !graph[i-1][j] && !graph[i-1][j-1]){
            if(!graph[i-1][j-2]) dp[i][j][2]+=dp[i-1][j-1][0];
            if(i>1 && !graph[i-2][j-1]){
                dp[i][j][2]+=dp[i-1][j-1][1];
                if(!graph[i-1][j-2] && !graph[i-2][j-2]) dp[i][j][2]+=dp[i-1][j-1][2];
            }
        }
        if(i>1 && !graph[i-1][j] && !graph[i-2][j]){
            dp[i][j][1]+=dp[i-1][j][1];
            if(!graph[i-1][j-1] && !graph[i-2][j-1]){
                dp[i][j][1]+=dp[i-1][j][2];
            }
        }
    }
    cout << dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];
    return 0;
}