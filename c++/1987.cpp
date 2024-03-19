#include <bits/stdc++.h>
using namespace std;

int n,r;
char f[20][20];
int d[20][20]={0,};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int ans=1;

void solve(int x, int y,vector<bool> check){
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(n<=nx || nx<0 || r<=ny || ny<0) continue;
        if(check[f[nx][ny]-'A']) continue;
        check[f[nx][ny]-'A']=true;
        d[nx][ny]=max(d[nx][ny],d[x][y]+1);
        solve(nx,ny,check);
        check[f[nx][ny]-'A']=false;
        ans=max(ans,d[nx][ny]);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> r;
    for(int i=0;i<n;i++) for(int j=0;j<r;j++) cin >> f[i][j];
    vector<bool> arr(26,0);
    arr[f[0][0]-'A']=true;
    d[0][0]=1;
    solve(0,0,arr);
    cout << ans;
    return 0;
}