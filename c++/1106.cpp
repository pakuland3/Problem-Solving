#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int c,n,ans=0; cin >> c >> n;
    pair<int, int> arr[20];
    int dp[100001]; fill(dp+1,dp+100001,0);
    for(int i=0;i<n;i++){cin >> arr[i].first >> arr[i].second;dp[arr[i].first]=max(dp[arr[i].first],arr[i].second);}
    for(int i=1;i<=100000;i++){
        for(int j=0;j<n;j++) if(i-arr[j].first>0 && dp[i-arr[j].first]>0) dp[i]=max(dp[i],dp[i-arr[j].first]+arr[j].second);
        if(dp[i]>=c){ans=i;break;}
    }
    cout << ans;
    return 0;
}