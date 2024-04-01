#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans=1; cin >> n; vector<int> arr(n),dp(n,1);
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++) if(arr[i]>arr[j]){dp[i]=max(dp[i],dp[j]+1);}
        ans=max(dp[i],ans);
    }
    cout << n-ans;
    return 0;
}