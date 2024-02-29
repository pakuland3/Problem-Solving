#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

bool graph[1001][1001];
bool vis[1001][1001][2];
int d[1001][1001][2];
int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

//ans is min value of two elem d[n-1][m-1][0,1]

void init(){
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        d[i][j][0]=INF;
        d[i][j][1]=INF;
    }
}

void bfs(){
    queue<pair<int, pair<int, int>>> q; //state position
    d[0][0][0]=1;
    vis[0][0][0]=true;
    q.push({0,{0,0}});
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        bool b=q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(n-1<nx || nx<0 || m-1<ny || ny<0) continue;
            if(vis[nx][ny][b]) continue;
            if(!graph[nx][ny]){
                d[nx][ny][b]=d[x][y][b]+1;
                vis[nx][ny][b]=true;
                q.push({b,{nx,ny}});
            }
            else{
                if(b) continue;
                d[nx][ny][1]=d[x][y][0]+1;
                vis[nx][ny][0]=true;
                q.push({1,{nx,ny}});
            }
        }
    }
    if(!vis[n-1][m-1][0] && !vis[n-1][m-1][1]){cout << -1; return;}
    cout << min(d[n-1][m-1][0],d[n-1][m-1][1]);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%1d",&graph[i][j]);
    init();
    memset(vis,false,sizeof(vis));
    bfs();
    return 0;
}