#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define INF 2501
typedef long long ll;
using namespace std;

int n;
int graph[50][50];
int d[50][50];
int vis[50][50];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
string a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fill(d[0],d[50],INF);
    for(int i=0;i<n;i++){
        cin >> a;
        for(int j=0;j<n;j++) graph[i][j]=a[j]-'0';
    }
    d[0][0]=0;
    queue<pii> q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        pii now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=now.fi+dx[i];
            int ny=now.se+dy[i];
            if(n<=nx || nx<0 || n<=ny || ny<0) continue;
            if(vis[nx][ny] && d[nx][ny]<=d[now.fi][now.se]+!graph[nx][ny]) continue;
            d[nx][ny]=d[now.fi][now.se]+!graph[nx][ny];
            vis[nx][ny]=1;
            q.push({nx,ny});
        }
    }
    cout << d[n-1][n-1];
    return 0;
}