#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int r,c;
int cnt[10][10];
char graph[10][10];
bool vis[10][10];
pii f,s;
queue<pii> q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("in_out/arhipelag/arhipelag.in.5","r",stdin);
    cin >> r >> c;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> graph[i][j];
    for(int i=0;i<c;i++){
        cnt[0][i]++;
        cnt[r-1][i]++;
    }
    for(int i=0;i<r;i++){
        cnt[i][0]++;
        cnt[i][c-1]++;
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        if(!vis[i][j] && graph[i][j]!='X'){
            q.push({i,j});
            vis[i][j]=1;
        }
        while(!q.empty()){
            int x=q.front().fi;
            int y=q.front().se;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(r<=nx || nx<0 || c<=ny || ny<0) continue;
                if(!vis[nx][ny]){
                    vis[nx][ny]=1;
                    if(graph[nx][ny]!='X') q.push({nx,ny});
                    else cnt[nx][ny]++;
                }
                else if(graph[nx][ny]=='X') cnt[nx][ny]++;
            }
        }
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(cnt[i][j]>2) graph[i][j]='.';
    bool d=0,e=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!d && graph[i][j]=='X'){
                f.fi=i;
                d=1;
            }
            if(!e && graph[r-(i+1)][j]=='X'){
                s.fi=r-(i+1);
                e=1;
            }
        }
    }
    d=0; e=0;
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            if(!d && graph[j][i]=='X'){
                f.se=i;
                d=1;
            }
            if(!e && graph[j][c-(i+1)]=='X'){
                s.se=c-(i+1);
                e=1;
            }
        }
    }
    // vector<string> aa;
    // freopen("in_out/arhipelag/arhipelag.out.5","r",stdin);
    // string bb;
    // while(cin >> bb) aa.push_back(bb);
    // if(aa.size()!=s.fi-f.fi+1){ cout << 0; return 0;}
    // if(aa[0].length()!=s.se-f.se+1){ cout << 0; return 0;}
    // for(int i=f.fi;i<=s.fi;i++){
    //     for(int j=f.se;j<=s.se;j++){
    //         if(aa[i-f.fi][j-f.se]!=graph[i][j]){
    //             cout << 0; return 0;
    //         }
    //     }
    // }
    // cout << 1;
    for(int i=f.fi;i<=s.fi;i++){
        for(int j=f.se;j<=s.se;j++) cout << graph[i][j];
        cout << '\n';
    }
}