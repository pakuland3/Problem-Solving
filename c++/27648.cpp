#include <bits/stdc++.h>
using namespace std;

int n,m,k,dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int>> q;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n,vector<int> (m,1));
    vector<vector<bool>> vis(n,vector<bool> (m,0));
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
	int y=q.front().second;
	int cur=arr[x][y];
	q.pop();
	for(int i=0;i<4;i++){
	    int nx=x+dx[i];
	    int ny=y+dy[i];
	    if(n<=nx || nx<0 || m<=ny || ny<0) continue;
	    if(vis[nx][ny]) continue;
	    vis[nx][ny]=1;
	    if(nx!=n-1 && ny!=m-1 && cur+1>=k){cout << "NO"; return 0;}
	    if(nx==n-1 && ny==m-1 && cur+1>k){cout << "NO"; return 0;}
	    arr[nx][ny]=cur+1;
	    q.push({nx,ny});
	}
    }
    cout << "YES\n";
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++) cout << arr[i][j] << ' ';
	cout << '\n';
    }
}