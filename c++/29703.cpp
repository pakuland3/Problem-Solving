#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

char g[1000][1000];
int d[1000][1000][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    fill(d[0][0],d[1000][0],3000000);
    int sx,sy,hx,hy;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin >> g[i][j];
        if(g[i][j]=='S'){
            sx=i;
            sy=j;
        }
        if(g[i][j]=='H'){
            hx=i;
            hy=j;
        }
    }
    d[sx][sy][0]=0;
    queue<pair<pair<int,int>,int>> q;
    q.push({{sx,sy},0});
    while(q.size()){
        pair<pair<int,int>,int> now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=now.fi.fi+dx[i];
            int ny=now.fi.se+dy[i];
            if(n<=nx || nx<0 || m<=ny || ny<0) continue;
            if(g[nx][ny]=='D') continue;
            if(g[nx][ny]=='F' && d[nx][ny][1]>d[now.fi.fi][now.fi.se][now.se]+1){
                d[nx][ny][1]=d[now.fi.fi][now.fi.se][now.se]+1;
                q.push({{nx,ny},1});
            }
            if(g[nx][ny]!='F' && d[nx][ny][now.se]>d[now.fi.fi][now.fi.se][now.se]+1){
                d[nx][ny][now.se]=d[now.fi.fi][now.fi.se][now.se]+1;
                q.push({{nx,ny},now.se});
            }
        }
    }
    cout << (d[hx][hy][1]==3000000?-1:d[hx][hy][1]);
    return 0;
}