#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    int MOD=1234567;
    cin >> t;
    vector<vector<int>> pws(10);
    pws[0].push_back(7);
    pws[1].push_back(2); pws[1].push_back(4);
    pws[2].push_back(1); pws[2].push_back(5); pws[2].push_back(3);
    pws[3].push_back(2); pws[3].push_back(6);
    pws[4].push_back(1); pws[4].push_back(5); pws[4].push_back(7);
    pws[5].push_back(4); pws[5].push_back(2); pws[5].push_back(6); pws[5].push_back(8);
    pws[6].push_back(3); pws[6].push_back(5); pws[6].push_back(9);
    pws[7].push_back(4); pws[7].push_back(8); pws[7].push_back(0);
    pws[8].push_back(5); pws[8].push_back(7); pws[8].push_back(9);
    pws[9].push_back(6); pws[9].push_back(8);
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> dp(n,vector<int> (10,0));
        for(int i=0;i<10;i++) dp[0][i]=1;
        for(int i=1;i<n;i++) for(int j=0;j<10;j++) {
            for(int k=0;k<pws[j].size();k++) dp[i][j]=(dp[i][j]+dp[i-1][pws[j][k]])%MOD; 
        }
        int ans=0;
        for(int i=0;i<10;i++) ans+=dp[n-1][i];
        cout << ans%MOD << '\n';
    }
    return 0;
}