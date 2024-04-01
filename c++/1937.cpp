#include <bits/stdc++.h>
using namespace std;

int n,dp[500][500],arr[500][500],ans=1,dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int solve(int x, int y){
    if(dp[x][y]!=-1) return dp[x][y];
    bool b=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(n<=nx || nx<0 || n<=ny || ny<0) continue;
        if(arr[nx][ny]>arr[x][y]){dp[x][y]=max(dp[x][y],solve(nx,ny)+1);b=1;}
    }
    if(!b) return 1;
    else return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){dp[i][j]=solve(i,j);ans=max(ans,dp[i][j]);}
    cout << ans;
    return 0;
}