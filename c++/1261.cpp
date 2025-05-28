#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int g[100][100],d[100][100];
    for(int i=0;i<m;i++){
        string a;
        cin >> a;
        for(int j=0;j<n;j++) g[i][j]=a[j]-'0';
    }
    fill(d[0],d[100],10000);
    d[0][0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(n<=nx || nx<0 || m<=ny || ny<0) continue;
            if(!g[ny][nx] && d[ny][nx]>d[y][x]){
                d[ny][nx]=d[y][x];
                q.push({nx,ny});
            }
            if(g[ny][nx] && d[ny][nx]>d[y][x]+1){
                d[ny][nx]=d[y][x]+1;
                q.push({nx,ny});
            }
        }
    }
    cout << d[m-1][n-1];
    return 0;
}