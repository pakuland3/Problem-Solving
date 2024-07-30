#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int p2=pow(2,n);
    vector<vector<int>> c(n,vector<int> (n));
    vector<vector<int>> dp(n,vector<int> (p2,-1));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> c[i][j];
    for(int i=0;i<n;i++) dp[0][(1 << i)]=c[0][i];
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=1;k<p2;k++){
                bool condition=(k&(1 << j)==0) && (dp[i-1][k]!=-1);
                if(condition) dp[i][k|(1 << j)]=dp[i-1][k]+c[i][j];
            }
        }
    }
    cout << dp[n-1][p2-1];
    return 0;
}