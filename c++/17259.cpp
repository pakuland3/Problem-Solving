#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int w[100][100];
int wt[100][100];
int t[100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<pair<int,int>> wk;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int b,n,m;
    cin >> b >> n >> m;
    wk.resize(n);
    for(auto &p:wk){
        int t;
        cin >> p.fi >> p.se >> t;
        wt[p.fi][p.se]=t;
        w[p.fi][p.se]=1;
    }
    int res=0;
    queue<pair<int,int>> q;
    for(int i=0;i<m+3*b;i++){
        if(i<m) q.push({0,0});
        int cnt=q.size();
        for(auto &p:wk) if(t[p.fi][p.se]) t[p.fi][p.se]--;
        while(cnt--){
            int x=q.front().fi;
            int y=q.front().se;
            q.pop();
            int process=0;
            for(int j=0;j<4;j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if(b==x || x<0 || b==y || y<0) continue;
                if(w[nx][ny] && t[nx][ny]==0){
                    res++;
                    process=1;
                    t[nx][ny]=wt[nx][ny];
                }
            }
            if(process) continue;
            if(x==0 && y==b-1) x++;
            else if(x==b-1 && y==b-1) y--;
            else if(x==0) y++;
            else if(y==b-1) x++;
            else y--;
            if(x==b-1 && y==-1) continue;
            q.push({x,y});
        }
    }
    cout << res;
    return 0;
}