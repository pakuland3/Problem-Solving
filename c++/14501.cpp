#include <bits/stdc++.h>
using namespace std;

int arr[15][2];
int dp[15];
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){cin >> arr[i][0] >> arr[i][1];}
    for(int i=0;i<n;i++){
        if(i+arr[i][0]<=n) dp[i]=arr[i][1];
        else dp[i]=0;
        for(int j=0;j<i;j++){
            if(j+arr[j][0]<=i){
                if(i+arr[i][0]<=n) dp[i]=max(dp[i],dp[j]+arr[i][1]);
                else dp[i]=max(dp[i],dp[j]);
            }
        }
    }
    sort(dp,dp+n);
    cout << dp[n-1];
}