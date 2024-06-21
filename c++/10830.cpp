#include <bits/stdc++.h>
#define MOD (int)1e3
typedef long long ll;
using namespace std;

int n;
vector<vector<int>> a;
vector<vector<int>> ans;

void solve(ll c){
    if(c%2!=0){
        if(c==1) return;
        solve(c/2);
        vector<vector<int>> tmp(ans);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=(tmp[i][0]*tmp[0][j])%MOD;
                for(int k=1;k<n;k++){
                    ans[i][j]=(ans[i][j]+tmp[i][k]*tmp[k][j])%MOD;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp[i][j]=ans[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=(tmp[i][0]*a[0][j])%MOD;
                for(int k=1;k<n;k++){
                    ans[i][j]=(ans[i][j]+tmp[i][k]*a[k][j])%MOD;
                }
            }
        }
    }
    else{
        solve(c/2);
        vector<vector<int>> tmp(ans);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=(tmp[i][0]*tmp[0][j])%MOD;
                for(int k=1;k<n;k++){
                    ans[i][j]=(ans[i][j]+tmp[i][k]*tmp[k][j])%MOD;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll b;
    cin >> n >> b;
    a.resize(n,vector<int> (n));
    ans.resize(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            a[i][j]%=1000;
            ans[i][j]=a[i][j];
        }
    }
    solve(b);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}