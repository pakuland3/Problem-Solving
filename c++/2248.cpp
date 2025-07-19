#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp[31][32];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,l,I;
    cin >> n >> l >> I;
    dp[0][0]=dp[0][1]=1;
    for(int i=1;i<n;i++){
        dp[i][0]=1;
        for(int j=1;j<=min(l,(ll)i+1);j++) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    }
    int L=n-1;
    while(L>0){
        int s=0;
        for(int i=0;i<=l;i++) s+=dp[L-1][i];
        if(I>s) cout << 1,I-=s,l--;
        else cout << 0;
        L--;
    }
    cout << (I>1?1:0);
    return 0;
}