#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int dp[500][500];
        int page[500];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=200000000;
        for(int i=0;i<n;i++) dp[i][i]=0;
        for(int i=0;i<n;i++){
            cin >> page[i];
            if(i!=0) page[i]+=page[i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i+1;j++){
                int a=page[i+j]-(j!=0?page[j-1]:0);
                for(int k=j;k<i+j;k++){
                    dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+a);
                }
            }
        }
        cout << dp[0][n-1] << '\n';
    }
    return 0;
}