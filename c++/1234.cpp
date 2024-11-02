#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n,k;
int r,g,b;
ll dp[101][101][101];

ll gf(ll a){
    ll t=a/3+1;
    int cnt=a/3;
    a=a/3*2+1;
    for(int i=0;i<cnt;i++) t*=a--;
    for(int i=2;i<=cnt;i++) t/=i;
    return t;
}

ll solve(ll f, int r, int g, int b){
    if(r<0 || g<0 || b<0) return 0;
    if(r==0 && g==0 && b==0) return 1;
    if(f>n) return 0;
    if(dp[r][g][b]!=0) return dp[r][g][b];
    dp[r][g][b]+=solve(f+1,r-f,g,b)+solve(f+1,r,g-f,b)+solve(f+1,r,g,b-f);
    if(!(f%2)) dp[r][g][b]+=(f/2+1)*(solve(f+1,r-f/2,g-f/2,b)+solve(f+1,r-f/2,g,b-f/2)+solve(f+1,r,g-f/2,b-f/2));
    if(!(f%3)) dp[r][g][b]+=gf(f)*solve(f+1,r-f/3,g-f/3,b-f/3);
    return dp[r][g][b];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> r >> g >> b;
    cout << solve(1,r,g,b);
    return 0;
}