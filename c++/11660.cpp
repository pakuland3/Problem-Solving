#include <bits/stdc++.h>
using namespace std;

int dp[1000];
int arr[1000];
int n;
int maxi=0;
int curst;
int i;
vector<int> ans;

int main(){
    cin >> n;
    fill(dp,dp+1000,1);
    for(i=0;i<n;i++) cin >> arr[i];
    for(i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]) dp[i]=max(dp[i],dp[j]+1);
        }
        maxi=max(maxi,dp[i]);
    }
    cout << maxi << '\n';
    curst=maxi;
    for(i=n-1;i>-1;i--){
        if(dp[i]==maxi){
            ans.push_back(arr[i]);
            curst--;
            break;
        }
    }
    for(;i>-1;i--){
        if(dp[i]==curst && arr[i]<ans.back() && curst>=1){
            ans.push_back(arr[i]);
            curst--;
        }
    }
    for(i=ans.size()-1;i>-1;i--) cout << ans[i] << ' ';
}