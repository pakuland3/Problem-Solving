#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> dir;
vector<vector<int>> pfx;
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int xm,ym,xb,yb,n;

ld d(ll x, ll y){
    ld nd=(x-xb)*(x-xb)+(y-yb)*(y-yb);
    return sqrt(nd);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ld ans=1e7;
    cout << fixed << setprecision(5);
    cin >> xm >> ym >> xb >> yb;
    cin >> n;
    pfx.resize(n,vector<int>(8,0));
    dir.resize(n);
    string s;
    cin >> s;
    int c=2;
    for(int i=0;i<n;i++){
        c=(c+s[i]-'0')%8;
        dir[i]=c;
        pfx[i][c]=1;
        if(i!=0) for(int j=0;j<8;j++) pfx[i][j]+=pfx[i-1][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<8;j++){
            int nx=xm;
            int ny=ym;
            for(int k=0;k<8;k++){
                int ndir=(k+j-dir[i]+8)%8;
                int cnt=pfx[n-1][k]-pfx[i][k]+(ndir==j);
                nx+=dx[ndir]*cnt;
                ny+=dy[ndir]*cnt;
            }
            ans=min(ans,d(nx,ny));
        }
        xm+=dx[dir[i]];
        ym+=dy[dir[i]];
    }
    cout << ans;
    return 0;
}