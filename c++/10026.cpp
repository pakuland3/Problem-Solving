#include <bits/stdc++.h>
using namespace std;

int n;
int ans[2]={0,0};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[100][100][2];
char graph[100][100];

void bfs(char c, int sx, int sy, bool cur){
    queue<pair<int, int>> q;
    vis[sx][sy][cur]=true;
    q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(n-1<nx || nx<0 || n-1<ny || ny<0) continue;
            if(vis[nx][ny][cur]) continue;
            if(graph[nx][ny]==c){
                q.push({nx,ny});
                vis[nx][ny][cur]=true;
            }
            else if(!cur){
                if(c=='R' && graph[nx][ny]=='G'){
                    q.push({nx,ny});
                    vis[nx][ny][0]=true;
                }
                else if(c=='G' && graph[nx][ny]=='R'){
                    q.push({nx,ny});
                    vis[nx][ny][0]=true;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> graph[i][j];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        if(!vis[i][j][0]){
            bfs(graph[i][j], i, j, 0);
            ans[0]++;
        }
        if(!vis[i][j][1]){
            bfs(graph[i][j], i, j, 1);
            ans[1]++;
        }
    }
    cout << ans[1] << ' ' << ans[0];
    return 0;
}