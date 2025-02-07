// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// ll dp[10][100000];

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--){
//         int n,m;
//         cin >> n >> m;
//         fill(dp[0],dp[10],-1);
//         for(int i=0;i<10;i++) dp[0][i%m]=i;
//         dp[0][11%m]=11;
//         for(int i=1;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(dp[i-1][j]==-1) continue;
//                 for(int k=0;k<10;k++){
//                     ll add=dp[i-1][j]*10+k;
//                     dp[i][add%m]=max(dp[i][add%m],add);
//                 }
//                 ll add=dp[i-1][j]*100+11;
//                 dp[i][add%m]=max(dp[i][add%m],add);
//             }
//         }
//         cout << dp[n-1][0] << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[10][100000];
int l[10][100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    ll p[19],add;
    for(int i=0;i<19;i++) p[i]=pow(10,i);
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        fill(dp[0],dp[10],-1);
        fill(l[0],l[10],0);
        for(int i=0;i<10;i++){
            dp[0][i%m]=i;
            l[0][i%m]=1;
        }
        l[0][11%m]=2;
        dp[0][11%m]=11;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i-1][j]==-1) continue;
                for(int k=0;k<10;k++){
                    add=p[l[i-1][j]]*k;
                    if(dp[i][(j+add)%m]<add+dp[i-1][j]){
                        l[i][(j+add)%m]=l[i-1][j]+1;
                        dp[i][(j+add)%m]=add+dp[i-1][j];
                    }
                }
                add=p[l[i-1][j]]*11;
                if(dp[i][(j+add)%m]<add+dp[i-1][j]){
                    l[i][(j+add)%m]=l[i-1][j]+2;
                    dp[i][(j+add)%m]=add+dp[i-1][j];
                }
            }
        }
        cout << dp[n-1][0] << '\n';
    }
    return 0;
}