#include <bits/stdc++.h>
using namespace std;

int t;
int n;

void solve(){
    int dp[100001][2];
    int arr[100001][2];
    cin >> n;
    int maxi;
    for(int i=0;i<n;i++) cin >> arr[i][0];
    for(int i=0;i<n;i++) cin >> arr[i][1];
    if(n!=1){
        for(int i=0;i<2;i++){dp[i][0]=arr[i][0];dp[i][1]=arr[i][1];}
        dp[1][0]+=dp[0][1]; dp[1][1]+=dp[0][0];
        maxi=max(dp[1][0],dp[1][1]);
    }
    else{
        for(int i=0;i<1;i++){dp[i][0]=arr[i][0];dp[i][1]=arr[i][1];}
        maxi=max(dp[0][0],dp[0][1]);
    }
    for(int i=2;i<n;i++){
        dp[i][0]=max(dp[i-1][1],max(dp[i-2][0],dp[i-2][1]))+arr[i][0];
        dp[i][1]=max(dp[i-1][0],max(dp[i-2][0],dp[i-2][1]))+arr[i][1];
        maxi=max(maxi,max(dp[i][0],dp[i][1]));
    }
    cout << maxi << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--){
        solve();        
    }
    return 0;
}