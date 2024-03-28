#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[100][10001]={0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<pair<int, int>> apps(n); //mem cost
    for(int i=0;i<n;i++) cin >> apps[i].first;
    for(int i=0;i<n;i++) cin >> apps[i].second;
    dp[0][apps[0].second]=apps[0].first;
    for(int i=1;i<n;i++){
        for(int j=0;j<10001;j++){
            dp[i][j]=dp[i-1][j];
            if(j-apps[i].second>=0){
                if(dp[i-1][j-apps[i].second]!=0) dp[i][j]=max(dp[i][j],dp[i-1][j-apps[i].second]+apps[i].first);
                else dp[i][j]=max(dp[i][j],apps[i].first);
            }
        }
    }
    for(int i=0;i<10001;i++) if(dp[n-1][i]>=m){cout << i;return 0;}
    return 0;
}