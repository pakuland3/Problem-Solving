#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    int x,y;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,r,c;
    cin >> n >> m >> r >> c;
    vector<vector<bool>> convi(n+1,vector<bool> (m+1,0));
    vector<int> p(r);
    vector<poi> room(r);
    for(int i=0;i<r;i++){
        cin >> room[i].x >> room[i].y >> p[i];
    }
    int t=2200;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    while(c--){
        int x,y;
        cin >> x >> y;
        convi[x][y]=1;
    }
    for(int i=0;i<r;i++){
        queue<poi> q;
        vector<vector<bool>> vis(n+1,vector<bool> (m+1,0));
        q.push({room[i].x,room[i].y});
        vis[room[i].x][room[i].y]=1;
        int mini=0;
        bool e=0;
        while(!q.empty() && !e){
            poi now=q.front();
            q.pop();
            for(int j=0;j<4;j++){
                int nx=now.x+dx[j];
                int ny=now.y+dy[j];
                if(m<nx || nx<1 || m<ny || ny<1) continue;
                if(vis[nx][ny]) continue;
                if(convi[nx][ny]){
                    if(mini!=0 && mini<abs(room[i].x-nx)+abs(room[i].y-ny)){
                        e=1;
                        break;
                    }
                    mini=abs(room[i].x-nx)+abs(room[i].y-ny);
                    t=min(t,mini*p[i]);
                }
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    cout << t;
    return 0;
}