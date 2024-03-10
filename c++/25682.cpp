#include <bits/stdc++.h>
using namespace std;

int n,m,k;
bool f[2001][2001]; //m*n board 0 black 1 white
int cnt[2001][2001][2]={0,};
char inc;

void init(){
    if(f[0][0]){
        cnt[0][0][0]=1;
        cnt[0][0][1]=0;
    }
    else{
        cnt[0][0][0]=0;
        cnt[0][0][1]=1;
    }
    for(int i=1;i<n;i++){
        if(i%2!=0){
            if(f[0][i]){
                cnt[0][i][0]=cnt[0][i-1][0];
                cnt[0][i][1]=cnt[0][i-1][1]+1;
            }
            else{
                cnt[0][i][0]=cnt[0][i-1][0]+1;
                cnt[0][i][1]=cnt[0][i-1][1];
            }
            if(f[i][0]){
                cnt[i][0][0]=cnt[i-1][0][0];
                cnt[i][0][1]=cnt[i-1][0][1]+1;
            }
            else{
                cnt[i][0][0]=cnt[i-1][0][0]+1;
                cnt[i][0][1]=cnt[i-1][0][1];
            }
        }
        else{
            if(!f[0][i]){
                cnt[0][i][0]=cnt[0][i-1][0];
                cnt[0][i][1]=cnt[0][i-1][1]+1;
            }
            else{
                cnt[0][i][0]=cnt[0][i-1][0]+1;
                cnt[0][i][1]=cnt[0][i-1][1];
            }
            if(!f[i][0]){
                cnt[i][0][0]=cnt[i-1][0][0];
                cnt[i][0][1]=cnt[i-1][0][1]+1;
            }
            else{
                cnt[i][0][0]=cnt[i-1][0][0]+1;
                cnt[i][0][1]=cnt[i-1][0][1];
            }
        }
    }
    for(int i=1;i<m;i++) for(int j=1;j<n;j++){
        if((i+j)%2!=0){
            if(f[i][j]){
                cnt[i][j][0]=cnt[i-1][j][0]+cnt[i][j-1][0];
                cnt[i][j][1]=cnt[i-1][j][1]+cnt[i][j-1][1]+1;
            }
            else{
                cnt[i][j][0]=cnt[i-1][j][0]+cnt[i][j-1][0]+1;
                cnt[i][j][1]=cnt[i-1][j][1]+cnt[i][j-1][1];
            }
        }
        else{
            if(!f[i][j]){
                cnt[i][j][0]=cnt[i-1][j][0]+cnt[i][j-1][0];
                cnt[i][j][1]=cnt[i-1][j][1]+cnt[i][j-1][1]+1;
            }
            else{
                cnt[i][j][0]=cnt[i-1][j][0]+cnt[i][j-1][0]+1;
                cnt[i][j][1]=cnt[i-1][j][1]+cnt[i][j-1][1];
            }
        }
    }
}

void solve(){
    int bans=1e7;
    int wans=1e7;
    int btmp, wtmp;
    for(int i=k-1;i<m;i++) for(int j=k-1;j<n;j++){
        btmp=cnt[i][j][0];
        wtmp=cnt[i][j][1];
        if(j-k>-1){
            btmp-=cnt[i][j-k][0];
            wtmp-=cnt[i][j-k][1];
        }
        if(i-k>-1){
            btmp-=cnt[i-k][j][0];
            wtmp-=cnt[i-k][j][1];
        }
        bans=min(bans,btmp);
        wans=min(wans,wtmp);
    }
    cout << min(bans,wans);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k; for(int i=0;i<m;i++) for(int j=0;j<n;j++){
        cin >> inc;
        if(inc=='B') f[i][j]=0;
        else f[i][j]=1;
    }
    init();
    solve();
    return 0;
}