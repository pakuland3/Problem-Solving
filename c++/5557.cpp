#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[101][21]={0,};
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    dp[0][arr[0]]=1;
    for(int i=1;i<n-1;i++) for(int j=0;j<21;j++){
        if(0<=j-arr[i] && j-arr[i]<21) dp[i][j]+=dp[i-1][j-arr[i]];
        if(0<=j+arr[i] && j+arr[i]<21) dp[i][j]+=dp[i-1][j+arr[i]];
    }
    cout << dp[n-2][arr[n-1]];
    return 0;
}