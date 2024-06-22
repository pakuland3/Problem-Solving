#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,sum=0;
    cin >> n;
    vector<int> a(n);
    for(int &t:a){cin >> t; sum+=t;}
    vector<vector<bool>> dp(2,vector<bool> (sum+1,0));
    sort(a.begin(),a.end(),greater<int> ());
    dp[0][0]=dp[1][0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            int add=j-a[i];
            if(dp[!(i%2)][j]) dp[i%2][j]=1;
            if(0<=add && dp[!(i%2)][add]) dp[i%2][j]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            int subtract=j+a[i];
            if(dp[!(i%2)][j]) dp[i%2][j]=1;
            if(subtract<=sum && dp[!(i%2)][subtract]) dp[i%2][j]=1;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int w;
        cin >> w;
        if(w<=sum && dp[(n-1)%2][w]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}