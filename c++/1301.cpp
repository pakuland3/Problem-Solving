#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[11][11][11][11][11][6][6],ans=0;
vector<int> cnt(6,0);
int n,sum=0;

ll solve(int c, int a, int b){
    if(c==0) return 1;
    if(dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][a][b]!=-1) return dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][a][b];
    ll k=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>0 && a!=i && b!=i){
            cnt[i]--;
            k+=solve(c-1,b,i);
            cnt[i]++;
        }
    }
    return dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][a][b]=k;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++){cin >> cnt[i];sum+=cnt[i];}
    cout << solve(sum,0,0);
    return 0;
}