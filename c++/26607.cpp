// wrong answer cuz i supposed that there are absolute advantage
//  
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// struct TeamStat{
//     ll sumofa,sumofb;
// };

// struct PlayerStat{
//     ll a,b;
// };

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int n,k,x;
//     cin >> n >> k >> x;
//     vector<PlayerStat> arr(n);
//     for(auto &p:arr) cin >> p.a >> p.b;
//     vector<vector<TeamStat>> dp(2,vector<TeamStat> (k+1));
//     dp[0][1].sumofa=arr[0].a;
//     dp[0][1].sumofb=arr[0].b;
//     for(int i=1;i<n;i++){
//         bool cur=i%2,back=!cur;
//         ll back_multi=dp[back][1].sumofa*dp[back][1].sumofb;
//         ll cur_multi=arr[i].a*arr[i].b;
//         dp[cur][1]=dp[back][1];
//         if(back_multi<cur_multi){
//             dp[cur][1].sumofa=arr[i].a;
//             dp[cur][1].sumofb=arr[i].b;
//         }
//         for(int j=2;j<=min(k,i+1);j++){
//             dp[cur][j]=dp[back][j];
//             back_multi=dp[back][j].sumofa*dp[back][j].sumofb;
//             cur_multi=(dp[back][j-1].sumofa+arr[i].a)*(dp[back][j-1].sumofb+arr[i].b);
//             if(back_multi<cur_multi){
//                 dp[cur][j].sumofa=dp[back][j-1].sumofa+arr[i].a;
//                 dp[cur][j].sumofb=dp[back][j-1].sumofb+arr[i].b;
//             }
//         }
//     }
//     cout << dp[(n-1)%2][k].sumofa*dp[(n-1)%2][k].sumofb;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,x,t;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i] >> t;
    vector<vector<vector<bool>>> dp(2,vector<vector<bool>> (k+1, vector<bool> (16001,0)));
    dp[0][1][a[0]]=1;
    for(int i=1;i<n;i++){
        bool cur=i%2,back=!cur;
        for(int j=1;j<=k;j++){
            for(int l=0;l<=16001;l++){
                dp[cur][j][l]=dp[back][j][l];
                bool c=((l>=a[i] && dp[back][j-1][l-a[i]])||(j==1 && l==a[i]));
                if(c) dp[cur][j][l]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=16001;i++){
        if(dp[(n-1)%2][k][i]) ans=max(ans,i*(k*x-i));
    }
    cout << ans;
    return 0;
}