#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t,n;
ll a[5000],dp[5000][5000],cur;
int opt[5000][5000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=0;i<5000;i++) opt[i][i]=i;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(i!=0) a[i]+=a[i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                dp[j][i+j]=dp[j][opt[j][i+j-1]]+dp[opt[j][i+j-1]+1][i+j]+a[i+j]-(j!=0?a[j-1]:0);
                opt[j][i+j]=opt[j][i+j-1];
                for(int k=opt[j][i+j-1]+1;k<=opt[j+1][i+j];k++){
                    cur=dp[j][k]+dp[k+1][i+j]+a[i+j]-(j!=0?a[j-1]:0);
                    if(dp[j][i+j]>cur){
                        dp[j][i+j]=cur;
                        opt[j][i+j]=k;
                    }
                }
            }
        }
        cout << dp[0][n-1] << '\n';    
    }
    return 0;
}