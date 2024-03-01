#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int n,m,k;
int d[1001][1001][11];
bool graph[1001][1001];
bool vis[1001][1001][11];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void init(){
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int l=0;l<11;l++) d[i][j][l]=INF;
}

void bfs(){
    queue<pair<int,pair<int, int>>> q;
    vis[0][0][0]=true;
    d[0][0][0]=1;
    q.push({0,{0,0}});
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        int bks=q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(n-1<nx || nx<0 || m-1<ny || ny<0) continue;
            if(vis[nx][ny][bks]) continue;
            if(!graph[nx][ny]){
                d[nx][ny][bks]=d[x][y][bks]+1;
                vis[nx][ny][bks]=true;
                q.push({bks,{nx,ny}});
            }
            else{
                if(bks==k) continue;
                d[nx][ny][bks+1]=d[x][y][bks]+1;
                vis[nx][ny][bks]=true;
                q.push({bks+1,{nx,ny}});
            }
        }
    }
    bool b=false;
    int ans=INF;
    for(int i=0;i<10;i++){
        if(vis[n-1][m-1][i]) b=true;
        ans=min(ans,d[n-1][m-1][i]);
    }
    if(!b){cout << -1;return;}
    cout << ans;
}

int main(){
    memset(vis,0,sizeof(vis));
    scanf("%d %d %d",&n,&m,&k);
    init();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%1d", &graph[i][j]);
    bfs();
    return 0;
}