#include <bits/stdc++.h>
using namespace std;

char board[5][5],f[5][5];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
vector<string> arr;

void solve(int x, int y, int scnt, int ycnt, char a[5][5]){
    if(scnt+ycnt==7){
        if(scnt<4) return;
        for(string anss:arr){
            for(int i=0;i<5;i++) for(int j=0;j<5;j++){
                if(a[i][j]==anss[i*5+j]) return;
            }
        }
        string inn(""); for(int i=0;i<5;i++) for(int j=0;j<5;j++) inn+=a[i][j];
        arr.push_back(inn);
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(4<nx || nx<0 || 4<ny || ny<0) continue;
        if(a[nx][ny]!='.') continue;
        if(board[nx][ny]=='S'){
            a[nx][ny]='S';
            solve(nx,ny,scnt+1,ycnt,a);
        }
        else{
            a[nx][ny]='Y';
            solve(nx,ny,scnt,ycnt+1,a);
        }
        a[nx][ny]='.';
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){cin >> board[i][j]; f[i][j]='.';}
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){
        f[i][j]=board[i][j];
        if(f[i][j]=='S') solve(i,j,1,0,f);
        else solve(i,j,0,1,f);
        f[i][j]='.';
    }
    cout << 1;
    cout << arr.size();
    return 0;
}