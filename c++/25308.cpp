#include <bits/stdc++.h>
#define r2 sqrt(2)
typedef long long ll;
using namespace std;

double aa[8];
double p[8][2]={{0,1},{1/r2,1/r2},{1,0},{1/r2,-1/r2},{0,-1},{-1/r2,-1/r2},{-1,0},{-1/r2,1/r2}};
int res=0;
bool vis[8];


struct poi{
    double x,y;
};

double CCW(poi a, poi b, poi c){
    return a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y;
}

void solve(poi f, poi s, poi a, poi b, int cnt, bool* vis){
    if(cnt==8){
        if(CCW(a,b,f)>0) return;
        if(CCW(b,f,s)>0) return;
        res++;
        return;
    }
    for(int i=0;i<8;i++){
        if(vis[i]) continue;
        poi c={aa[i]*p[cnt][0],aa[i]*p[cnt][1]};
        if(CCW(a,b,c)>0) continue;
        vis[i]=1;
        solve(f,s,b,c,cnt+1,vis);
        vis[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=0;i<8;i++) cin >> aa[i];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==j) continue;
            poi a={aa[i]*p[0][0],aa[i]*p[0][1]};
            poi b={aa[j]*p[1][0],aa[j]*p[1][1]};
            vis[i]=1;
            vis[j]=1;
            solve(a,b,a,b,2,vis);
            vis[i]=0;
            vis[j]=0;
        }
    }
    cout << res;
    return 0;
}