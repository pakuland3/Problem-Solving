#include <bits/stdc++.h>
using namespace std;

int n,m,ans=0;
pair<int, int> p1,p2;
char graph[300][300];
bool flag=false;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs(){
    bool vis[300][300]; memset(vis,0,sizeof(vis));
    queue<pair<int, int>> q;
    q.push({p1.first, p1.second});
    vis[p1.first][p1.second]=true;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(n-1<nx || nx<0 || m-1<ny || ny<0) continue;
            if(vis[nx][ny]) continue;
            if(graph[nx][ny]=='1') graph[nx][ny]='0';
            else if(graph[nx][ny]=='0') q.push({nx,ny});
            else flag=true;
            vis[nx][ny]=true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> p1.first >> p1.second >> p2.first >> p2.second;
    p1.first--; p1.second--;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> graph[i][j];
    queue<pair<int, int>> q;
    while(!flag){
        bfs();
        ans++;
    }
    cout << ans;
    return 0;
}