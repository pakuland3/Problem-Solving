// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int n,m;
// int dp[50][50];
// int dx[]={1,-1,0,0};
// int dy[]={0,0,1,-1};
// bool vis[50][50];
// char graph[50][50];

// int dfs(int x, int y){
//     if(n<=x || x<0 || m<=y || y<0 || graph[x][y]=='H') return 0;
//     if(dp[x][y]!=-1) return dp[x][y];
//     vis[x][y]=1;
//     for(int i=0;i<4;i++){
//         int nx=x+(graph[x][y]-'0')*dx[i];
//         int ny=y+(graph[x][y]-'0')*dy[i];
//         if(0<=nx && nx<n && 0<=ny && ny<m) if(vis[nx][ny]) return -1;
//         int tmp=dfs(nx,ny);
//         if(tmp==-1) return -1;
//         dp[x][y]=max(dp[x][y],tmp+1);
//     }
//     vis[x][y]=0;
//     return dp[x][y];
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n >> m;
//     for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> graph[i][j];
//     memset(dp,-1,sizeof(dp));
//     cout << dfs(0,0);
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,m;
int dp[50][50];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[50][50];
char graph[50][50];

int dfs(int x, int y){
    if(n<=x || x<0 || m<=y || y<0 || graph[x][y]=='H') return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    for(int i=0;i<4;i++){
        int nx=x+(graph[x][y]-'0')*dx[i];
        int ny=y+(graph[x][y]-'0')*dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<m){
            if(vis[nx][ny]) return -1;
            vis[nx][ny]=1;
        }
        int tmp=dfs(nx,ny);
        if(0<=nx && nx<n && 0<=ny && ny<m) vis[nx][ny]=0;
        if(tmp==-1) return -1;
        dp[x][y]=max(dp[x][y],tmp+1);
    }
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> graph[i][j];
    vis[0][0]=1;
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0);
    return 0;
}