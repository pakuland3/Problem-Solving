#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll fact[11];
ll dp[56][56][56];
ll n,res=0;
int r,g,b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fact[1]=1;
    for(int i=2;i<11;i++) fact[i]=fact[i-1]*i;
    vector<int> f; for(int i=1;i<11;i++) f.push_back(i*(i+1)/2);
    cin >> n >> r >> g >> b;
    r=min(r,55);
    g=min(g,55);
    b=min(b,55);
    dp[0][0][0]=1;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=g;j++){
            for(int k=0;k<=b;k++){
                auto it=lower_bound(f.begin(),f.end(),i+j+k);
                if(it==f.end() || *it!=i+j+k) continue;
                ll d=it-f.begin()+1;
                if(i>=d) dp[i][j][k]+=dp[i-d][j][k];
                if(j>=d) dp[i][j][k]+=dp[i][j-d][k];
                if(k>=d) dp[i][j][k]+=dp[i][j][k-d];
                if(d%2==0 && i>=d/2 && j>=d/2) dp[i][j][k]+=fact[d]/fact[d/2]/fact[d/2]*dp[i-d/2][j-d/2][k];
                if(d%2==0 && j>=d/2 && k>=d/2) dp[i][j][k]+=fact[d]/fact[d/2]/fact[d/2]*dp[i][j-d/2][k-d/2];
                if(d%2==0 && i>=d/2 && k>=d/2) dp[i][j][k]+=fact[d]/fact[d/2]/fact[d/2]*dp[i-d/2][j][k-d/2];
                if(d%3==0 && i>=d/3 && j>=d/3 && k>=d/3) dp[i][j][k]+=fact[d]/fact[d/3]/fact[d/3]/fact[d/3]*dp[i-d/3][j-d/3][k-d/3];
                if(d==n) res+=dp[i][j][k];
            }
        }
    }
    cout << res;
    return 0;
}