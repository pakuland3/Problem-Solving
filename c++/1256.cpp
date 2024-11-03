#include <bits/stdc++.h>
#define INF 1000000000
typedef long long ll;
using namespace std;

int dp[101][101];
int n,m,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=m;i++) dp[0][i]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j]=min(dp[i-1][j]+dp[i][j-1],INF);
    if(dp[n][m]<k){
        cout << -1;
        return 0;
    }
    int a=n,z=m;
    while(a!=0 || z!=0){
        if(a==0){
            cout << 'z';
            z--;
            continue;
        }
        if(z==0){
            cout << 'a';
            a--;
            continue;
        }
        if(dp[a-1][z]>=k){
            cout << 'a';
            a--;
        }
        else{
            cout << 'z';
            k-=dp[a-1][z];
            z--;
        }
    }
    return 0;
}