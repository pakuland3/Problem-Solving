#include <bits/stdc++.h>
using namespace std;

int m,n,k;
vector<int> ans;
bool vis[100][100]={0,};
bool graph[100][100]={0,};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int dbfs(int x, int y){
    queue<pair<int, int>> q;
    int wh=1;
    vis[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(m<=nx || nx<0 || n<=ny || ny<0) continue;
            if(!vis[nx][ny] && !graph[nx][ny]){wh++;vis[nx][ny]=true;q.push({nx,ny});}
        }
    }
    return wh;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        int x[2],y[2]; cin >> y[0] >> x[0] >> y[1] >> x[1];
        for(int j=x[0];j<x[1];j++) for(int l=y[0];l<y[1];l++) graph[j][l]=1;
    }
    for(int i=0;i<m;i++) for(int j=0;j<n;j++){
        if(!vis[i][j] && !graph[i][j]) ans.push_back(dbfs(i,j));
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int o:ans) cout << o << ' ';
    return 0;
}