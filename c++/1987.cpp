#include <bits/stdc++.h>
using namespace std;

int r,c;
char f[20][20];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int ans=1;

void solve(int x, int y,int cnt,bool check[26]){
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(r<=nx || nx<0 || c<=ny || ny<0) continue;
        if(check[f[nx][ny]-'A']) continue;
        check[f[nx][ny]-'A']=true;
        cnt++;
        solve(nx,ny,cnt,check);
        check[f[nx][ny]-'A']=false;
        ans=max(ans,cnt);
        cnt--;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> f[i][j];
    bool arr[26]={0,};
    arr[f[0][0]-'A']=true;
    solve(0,0,1,arr);
    cout << ans;
    return 0;
}