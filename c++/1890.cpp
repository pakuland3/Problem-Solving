#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dx[]={0,1};
int dy[]={1,0};
int graph[100][100];
ll dp[100][100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> graph[i][j];
    dp[0][0]=1;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<2;k++){
        if(graph[i][j]==0) break;
        int nx=i+dx[k]*graph[i][j];
        int ny=j+dy[k]*graph[i][j];
        if(n<=nx || nx<0 || n<=ny || ny<0) continue;
        dp[nx][ny]+=dp[i][j];
    }
    cout << dp[n-1][n-1];
    return 0;
}