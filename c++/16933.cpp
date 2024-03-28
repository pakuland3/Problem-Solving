#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s;
bool graph[1000][1000],vis[1000][1000][11]={0,};
int d[1000][1000][11]={0,};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void solve(){
    queue<pair<pair<int, int>, pair<int, pair<bool, bool>>>> q;
    q.push({{0,0},{0,{0,0}}});
    vis[0][0][0]=true;
    d[0][0][0]=1;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int breaks=q.front().second.first;
        bool time=q.front().second.second.first;
        bool isRest=q.front().second.second.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(n<=nx || nx<0 || m<=ny || ny<0) continue;
            if(vis[nx][ny][breaks]) continue;
            if(!graph[nx][ny]){
                vis[nx][ny][breaks]=true;
                d[nx][ny][breaks]=d[x][y][breaks]+1;
                q.push({{nx,ny},{breaks,{!time,0}}});
            }
            else{
                if(breaks==k) continue;
                if(!time){
                    if(!isRest) d[nx][ny][breaks+1]=d[x][y][breaks]+1;
                    else d[nx][ny][breaks+1]=d[x][y][breaks]+2;
                    vis[nx][ny][breaks]=true;
                    vis[nx][ny][breaks+1]=true;
                    q.push({{nx,ny},{breaks+1,{!time,0}}});
                }
                else q.push({{x,y},{breaks,{!time,1}}});
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<11;i++) if(d[n-1][m-1][i]!=0) ans=min(ans,d[n-1][m-1][i]);
    if(ans==1e9){cout << -1; return;}
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++) graph[i][j]=s[j]-'0';
    }
    solve();
    return 0;
}