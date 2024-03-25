#include <bits/stdc++.h>
using namespace std;

int n,r,c,cnt=-1;
int nr,nc;
int dr[]={0,0,1,1};
int dc[]={0,1,0,1};
bool b=false;

void solve(int x, int y, int l){
    if(b) return;
    if(l==2){
        for(int i=0;i<4;i++){
            nr=x+dr[i];
            nc=y+dc[i];
            cnt++;
            if(nr==r && nc==c){cout << cnt; b=true; return;}
        }
    }
    else{
        if(x<=r && r<x+l/2 && y<=c && c<y+l/2){solve(x,y,l/2); return;}
        cnt+=l*l/4;
        if(x<=r && r<x+l/2 && y+l/2<=c && c<y+l){solve(x,y+l/2,l/2); return;}
        cnt+=l*l/4;
        if(x+l/2<=r && r<x+l && y<=c && c<y+l/2){solve(x+l/2,y,l/2); return;}
        cnt+=l*l/4;
        if(x+l/2<=r && r<x+l && y+l/2<=c && c<y+l){solve(x+l/2,y+l/2,l/2); return;}
        cnt+=l*l/4;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> r >> c;
    solve(0,0,pow(2,n));
    return 0;
}