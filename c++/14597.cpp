#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp[100][100];
int a1[100][100],a2[100][100];
int h,w;

int d(int i,int j){
    return (a1[i][j]-a2[i][j])*(a1[i][j]-a2[i][j]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> h >> w;
    int ans=INT32_MAX;
    fill(dp[0],dp[100],INT32_MAX);
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> a1[i][j];
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> a2[i][j];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0) dp[i][j]=d(i,j);
            else{
                for(int l:{j-1,j,j+1}){
                    if(w<=l || l<0) continue;
                    dp[i][j]=min(dp[i][j],dp[i-1][l]+d(i,j));
                }
            }
            if(i==h-1) ans=min(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}