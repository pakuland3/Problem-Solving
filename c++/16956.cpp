#include <bits/stdc++.h>
using namespace std;

int r,c;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool ans=true;
bool vis[500][500]={0,};
char b[500][500];
queue<pair<int, int>> q;
string s;

void bfs(){
    while(!q.empty()){
        if(!ans) break;
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(r<nx || nx<0 || c<ny || ny<0) continue;
            if(b[nx][ny]=='S') ans=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i=0;i<r;i++){
        cin >> s;
        for(int j=0;j<c;j++){
            b[i][j]=s[j];
            if(b[i][j]=='W'){q.push({i,j});vis[i][j]=1;}
            else if(b[i][j]=='.') b[i][j]='D';
        }
    }
    bfs();
    if(!ans) cout << 0;
    else{
        cout << "1\n";
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << b[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}