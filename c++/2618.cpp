#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp[1002][1002];
int x[1002],y[1002];

int d(int a, int b, int c, int d){ return abs(a-c)+abs(b-d); };

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    fill(dp[0],dp[1002],2e6);
    for(int i=1;i<=m;i++) cin >> x[i] >> y[i];
    dp[0][0]=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            int nx=max(i,j)+1;
            if(i==0) x[0]=1,y[0]=1;
            dp[nx][j]=min(dp[nx][j],dp[i][j]+d(x[i],y[i],x[nx],y[nx]));
            if(j==0) x[0]=n,y[0]=n;
            dp[i][nx]=min(dp[i][nx],dp[i][j]+d(x[j],y[j],x[nx],y[nx]));
        }
    }
    int mx=m,my=0;
    for(int i=0;i<m;i++){
        if(dp[m][i]<dp[mx][my]){
            mx=m;
            my=i;
        }
        if(dp[i][m]<dp[mx][my]){
            mx=i;
            my=m;
        }
    }
    cout << dp[mx][my] << '\n';
    vector<int> ans;
    while(mx!=0 || my!=0){
        int t=0,c;
        if(mx<my){
            ans.push_back(2);
            if(my==mx+1){
                c=dp[mx][0]+d(n,n,x[my],y[my]);
                for(int i=1;i<mx;i++) if(c>dp[mx][i]+d(x[i],y[i],x[my],y[my])){
                    c=dp[mx][i]+d(x[i],y[i],x[my],y[my]);
                    t=i;
                }
                my=t;
            }
            else my--;
        }
        else{
            ans.push_back(1);
            if(mx==my+1){
                c=dp[0][my]+d(1,1,x[mx],y[mx]);
                for(int i=1;i<my;i++) if(c>dp[i][my]+d(x[i],y[i],x[mx],y[mx])){
                    c=dp[i][my]+d(x[i],y[i],x[mx],y[mx]);
                    t=i;
                }
                mx=t;
            }
            else mx--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int &t:ans) cout << t << '\n';
    return 0;
}