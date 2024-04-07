#include <bits/stdc++.h>
using namespace std;

int ans=0;
char board[5][5];

bool ck(int x, int y, char tmp[5][5]){
    queue<pair<int, int>> q;
    bool vis[5][5]={0,}; vis[x][y]=1;
    int dx[]={1,-1,0,0},dy[]={0,0,1,-1},acnt=1;
    q.push({x,y});
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(4<nx || nx<0 || 4<ny || ny<0) continue;
            if(tmp[nx][ny]=='.') continue;
            if(vis[nx][ny]) continue;
            q.push({nx,ny});
            vis[nx][ny]=1;
            acnt++;
        }
    }
    if(acnt!=7) return false;
    return true;
}

void backTracking(int x, int y, int scnt, int ycnt, char tmp[5][5]){
    if(scnt+ycnt==7){
        if(ck(x,y,tmp)) ans++;
        return;
    }
    for(int i=x;i<5;i++) for(int j=0;j<5;j++){
        if(i==x && j<=y) continue;
        tmp[i][j]=board[i][j];
        if(tmp[i][j]=='Y' && ycnt<3) backTracking(i,j,scnt,ycnt+1,tmp);
        if(tmp[i][j]=='S') backTracking(i,j,scnt+1,ycnt,tmp);
        tmp[i][j]='.';
    }
    return;
}

void solve(){
    char f[5][5]; for(int i=0;i<5;i++) for(int j=0;j<5;j++) f[i][j]='.';
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){
        f[i][j]=board[i][j];
        if(f[i][j]=='Y') backTracking(i,j,0,1,f);
        if(f[i][j]=='S') backTracking(i,j,1,0,f);
        f[i][j]='.';
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) cin >> board[i][j];
    solve();
    return 0;
}