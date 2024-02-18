#include <bits/stdc++.h>
using namespace std;

int n,m;
int cnt[50][50];
bool g[50][50];
bool tmp;
bool ansB=true;
int ans=0;
bool f[50][50]; //true -> have to change
                //false -> do not change
int main(){
    memset(cnt,0,sizeof(cnt));
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){scanf("%1d",&g[i][j]);}
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        scanf("%1d",&tmp);
        if(!tmp){
            if(!g[i][j]) f[i][j]=false;
            else f[i][j]=true;
        }
        else{
            if(g[i][j]) f[i][j]=false;
            else f[i][j]=true;
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        bool t=false;
        if(cnt[i][j]%2==0 && f[i][j]) t=true;
        else if(cnt[i][j]%2!=0 && !f[i][j]) t=true;
        if(t){
            if(i+2<n && j+2<m){
                for(int h=i;h<i+3;h++) for(int k=j;k<j+3;k++){
                    cnt[h][k]++;
                }
                ans++;
            }
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(f[i][j] && cnt[i][j]%2==0) ansB=false;
        else if(!f[i][j] && cnt[i][j]%2!=0) ansB=false;
    }
    if(ansB) cout << ans;
    else cout << -1;
}