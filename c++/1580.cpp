#include <bits/stdc++.h>
#define x first
#define y second
#define C(k) (n<=k.x || k.x<0 || m<=k.y || k.y<0)
#define D(k) (g[k.x][k.y]=='X')
typedef long long ll;
using namespace std;

int n,m;
char g[20][20];
int d[20][20][20][20];
int dx[]={0,-1,-1,-1,0,1,1,1,0};
int dy[]={0,-1,0,1,1,1,0,-1,-1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill(d[0][0][0],d[20][0][0],999);
    cin >> n >> m;
    int ax,ay,bx,by;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin >> g[i][j];
        if(g[i][j]=='A'){
            ax=i;
            ay=j;
        }
        if(g[i][j]=='B'){
            bx=i;
            by=j;
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{ax,ay},{bx,by}});
    d[ax][ay][bx][by]=0;
    while(q.size()){
        pair<int,int> a=q.front().first;
        pair<int,int> b=q.front().second;
        int c=d[a.x][a.y][b.x][b.y];
        q.pop();
        for(int i=0;i<9;i++){
            pair<int,int> na={a.x+dx[i],a.y+dy[i]};
            if(C(na) || D(na)) continue;
            for(int j=0;j<9;j++){
                pair<int,int> nb={b.x+dx[j],b.y+dy[j]};
                if(C(nb) || D(nb)) continue;
                if(na.x==nb.x && na.y==nb.y) continue;
                if(na.x==b.x && na.y==b.y && nb.x==a.x && nb.y==a.y) continue;
                if(d[na.x][na.y][nb.x][nb.y]>c+1){
                    q.push({na,nb});
                    d[na.x][na.y][nb.x][nb.y]=c+1;
                }
            }
        }
    }
    cout << (d[bx][by][ax][ay]==999?-1:d[bx][by][ax][ay]);
    return 0;
}