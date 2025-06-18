#include <bits/stdc++.h>
#define fi first
#define se second
#define x first
#define y second
#define pii pair<int,int>
#define C(k) (n<=k.x || k.x<0 || m<=k.y || k.y<0)
typedef long long ll;
using namespace std;

int d[11][11][11][11][6];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char r[]={'R','D','L','U'};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill(d[0][0][0][0],d[11][0][0][0],200);
    int n,m,nx,ny;
    cin >> n >> m;
    char g[11][11];
    int rx,ry,bx,by,hx,hy;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin >> g[i][j];
        if(g[i][j]=='R') rx=i,ry=j;
        if(g[i][j]=='B') bx=i,by=j;
        if(g[i][j]=='O') hx=i,hy=j;
    }
    queue<pair<pii,pii>> q;
    q.push({{rx,ry},{bx,by}});
    d[rx][ry][bx][by][0]=0;
    while(q.size()){
        pii a=q.front().fi;
        pii b=q.front().se;
        int c=d[a.x][a.y][b.x][b.y][0];
        q.pop();
        for(int i=0;i<4;i++){
            pii na=a;
            pii nb=b;
            pii t={-1,-1};
            int amov=0;
            int bmov=0;
            int imp=0;
            while(1){
                int f=0;
                nx=nb.x+dx[i];
                ny=nb.y+dy[i];
                if(!C(make_pair(nx,ny)) && g[nx][ny]!='#'){
                    if(g[nx][ny]=='O'){
                        imp=1;
                        break;
                    }
                    nb={nx,ny};
                    bmov++;
                    f=1;
                }
                nx=na.x+dx[i];
                ny=na.y+dy[i];
                if(!C(make_pair(nx,ny)) && g[nx][ny]!='#'){
                    if(g[nx][ny]=='O') t=nb;
                    na={nx,ny};
                    amov++;
                    f=1;
                }
                if(na==nb){
                    if(amov==bmov) imp=1;
                    else if(amov<bmov) nb={nb.x-dx[i],nb.y-dy[i]};
                    else na={na.x-dx[i],na.y-dy[i]};
                    break;
                }
                if(!f) break;
            }
            if(imp) continue;
            if(t.x!=-1){
                if(d[hx][hy][t.x][t.y][0]>c+1){
                    d[hx][hy][t.x][t.y][0]=c+1;
                    d[hx][hy][t.x][t.y][1]=i;
                    d[hx][hy][t.x][t.y][2]=a.x;
                    d[hx][hy][t.x][t.y][3]=a.y;
                    d[hx][hy][t.x][t.y][4]=b.x;
                    d[hx][hy][t.x][t.y][5]=b.y;
                }
            }
            if(d[na.x][na.y][nb.x][nb.y][0]>c+1){
                q.push({na,nb});
                d[na.x][na.y][nb.x][nb.y][0]=c+1;
                d[na.x][na.y][nb.x][nb.y][1]=i;
                d[na.x][na.y][nb.x][nb.y][2]=a.x;
                d[na.x][na.y][nb.x][nb.y][3]=a.y;
                d[na.x][na.y][nb.x][nb.y][4]=b.x;
                d[na.x][na.y][nb.x][nb.y][5]=b.y;
            }
        }
    }
    int res=200;
    pair<pii,pii> s;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(res>d[hx][hy][i][j][0]){
            res=d[hx][hy][i][j][0];
            s={{hx,hy},{i,j}};
        }
    }
    if(res>10){
        cout << -1;
        return 0;
    }
    vector<int> ans;
    while(s.fi!=make_pair(rx,ry) || s.se!=make_pair(bx,by)){
        ans.push_back(d[s.fi.x][s.fi.y][s.se.x][s.se.y][1]);
        s={{d[s.fi.x][s.fi.y][s.se.x][s.se.y][2],d[s.fi.x][s.fi.y][s.se.x][s.se.y][3]},
        {d[s.fi.x][s.fi.y][s.se.x][s.se.y][4],d[s.fi.x][s.fi.y][s.se.x][s.se.y][5]}};
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int t:ans) cout << r[t];
    return 0;
}