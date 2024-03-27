#include <bits/stdc++.h>
using namespace std;

int n,m,ocean[300][300],ans=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int ck(){
    bool vis[300][300]={0,};
    int cnt=0;
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(ocean[i][j]>0 && !vis[i][j]){
            q.push({i,j});
            vis[i][j]=true;
            cnt++;
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(n<=nx || nx<0 || m<=ny || ny<0) continue;
                    if(vis[nx][ny]) continue;
                    if(!vis[nx][ny] && ocean[nx][ny]>0){q.push({nx,ny}); vis[nx][ny]=true;}
                }
            }
        }
    }
    if(cnt>1) return 1;
    if(cnt==0) return 2;
    return 0;
}

void dobfs(){
    bool vis[300][300]={0,};
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(ocean[i][j]==0 && !vis[i][j]){
            q.push({i,j});
            vis[i][j]=true;
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(n<=nx || nx<0 || m<=ny || ny<0) continue;
                    if(vis[nx][ny]) continue;
                    if(!vis[nx][ny] && ocean[nx][ny]>0){ocean[nx][ny]--; if(ocean[nx][ny]==0) vis[nx][ny]=true;}
                    else{q.push({nx,ny});vis[nx][ny]=true;}
                }
            }
        }
    }
}

void solve(){
    while(true){
        int t=ck();
        if(t==0){dobfs(); ans++;}
        else if(t==1) break;
        else {cout << 0; return;}
    }
    cout << ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> ocean[i][j];
    solve();
}