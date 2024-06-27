#include <bits/stdc++.h>
#define MOD 10000
typedef long long ll;
using namespace std;

vector<vector<ll>> a(2,vector<ll> (2,1)),ans(a);

void solve(ll c){
    if(c<=1) return;
    if(c%2!=0){
        solve(c/2);
        vector<vector<ll>> tmp(ans);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                ans[i][j]=(tmp[i][0]*tmp[0][j])%MOD;
                ans[i][j]=(ans[i][j]+tmp[i][1]*tmp[1][j])%MOD;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                tmp[i][j]=ans[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                ans[i][j]=(tmp[i][0]*a[0][j])%MOD;
                ans[i][j]=(ans[i][j]+tmp[i][1]*a[1][j])%MOD;
            }
        }
    }
    else{
        solve(c/2);
        vector<vector<ll>> tmp(ans);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                ans[i][j]=(tmp[i][0]*tmp[0][j])%MOD;
                ans[i][j]=(ans[i][j]+tmp[i][1]*tmp[1][j])%MOD;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1){
        ll n;
        a[1][1]=0;
        a[0][0]=a[0][1]=a[1][0]=1;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) ans[i][j]=a[i][j];
        cin >> n;
        if(n==-1) break;
        if(n==0){
            cout << "0\n";
            continue;
        }
        solve(n-1);
        cout << ans[0][0] << '\n';
    }
    return 0;
}