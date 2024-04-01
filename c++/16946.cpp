#include <bits/stdc++.h>
using namespace std;

bool f[1000][1000],vis[1000][1000]={0,};
int ans[1000][1000]={0,};

void solve(){
    int n,m,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
    string s;
    queue<pair<int, int>> q,cq;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++) f[i][j]=s[j]-'0';
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(!f[i][j] && !vis[i][j]){
            int cnt=1;
            q.push({i,j});
            vis[i][j]=1;
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int l=0;l<4;l++){
                    int nx=x+dx[l];
                    int ny=y+dy[l];
                    if(n<=nx || nx<0 || m<=ny || ny<0) continue;
                    if(vis[nx][ny]) continue;
                    if(f[nx][ny]){cq.push({nx,ny});vis[nx][ny]=1;}
                    else{vis[nx][ny]=1; q.push({nx,ny}); cnt++;}
                }
            }
            while(!cq.empty()){
                ans[cq.front().first][cq.front().second]+=cnt;
                vis[cq.front().first][cq.front().second]=0;
                cq.pop();
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << (f[i][j]+ans[i][j])%10;
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}