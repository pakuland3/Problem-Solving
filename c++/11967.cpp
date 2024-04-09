#include <bits/stdc++.h>
using namespace std;

int n,m,t1,t2,a,b,ans=1,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bool barn[100][100]={0,}, vis[100][100]={0,};
vector<pair<int, int>> sw[100][100];
queue<pair<int, int>> q;

int main(){
    // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> t1 >> t2 >> a >> b; t1--; t2--; a--; b--;
        sw[t1][t2].push_back({a,b});
    }
    q.push({0,0}); barn[0][0]=1; vis[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(auto p:sw[x][y]){
            if(vis[p.first][p.second]) continue;
            if(barn[p.first][p.second]) continue;
            ans++;
            barn[p.first][p.second]=1;
            for(int i=0;i<4;i++){
                int nx=p.first+dx[i];
                int ny=p.second+dy[i];
                if(n<=nx || nx<0 || n<=ny || ny<0) continue;
                if(barn[nx][ny] && vis[nx][ny]){
                    q.push({p.first,p.second});
                    vis[p.first][p.second]=1;
                    break;
                }
            }
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(n<=nx || nx<0 || n<=ny || ny<0) continue;
            if(vis[nx][ny]) continue;
            if(barn[nx][ny]){vis[nx][ny]=1; q.push({nx,ny});}
        }
    }
    cout << ans;
    return 0;
}