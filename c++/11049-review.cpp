#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    pair<int,int> matrix[500];
    int dp[500][500];
    int n;
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=INT32_MAX;
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i=0;i<n;i++) cin >> matrix[i].fi >> matrix[i].se;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            for(int k=j;k<i+j;k++){
                dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+matrix[j].fi*matrix[k+1].fi*matrix[i+j].se);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}