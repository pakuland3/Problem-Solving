#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll n,m;

void solve(vector<vector<ll>> &a, vector<vector<ll>> &b, ll c){
    if(c==1) return;
    solve(a,b,c/2);
    vector<vector<ll>> tmp(m,vector<ll> (m,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                tmp[i][j]=(tmp[i][j]+a[i][k]*a[k][j]%MOD)%MOD;
            }
        }
    }
    if(c%2){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                a[i][j]=0;
                for(int k=0;k<m;k++){
                    a[i][j]=(a[i][j]+tmp[i][k]*b[k][j]%MOD)%MOD;
                }
            }
        }
    }
    else for(int i=0;i<m;i++) for(int j=0;j<m;j++) a[i][j]=tmp[i][j];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    if(m>=n){ cout << 1+(m==n); return 0; }
    vector<vector<ll>> a(m,vector<ll> (m,0));
    a[0][0]=1;
    a[0][m-1]=1;
    for(int i=1;i<m;i++) a[i][i-1]=1;
    vector<vector<ll>> b(a);
    solve(a,b,n-m);
    ll ans=a[0][0];
    for(int i=0;i<m;i++) ans=(ans+a[0][i])%MOD;
    cout << ans;
    return 0;
}