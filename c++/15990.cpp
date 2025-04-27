#include <bits/stdc++.h>
#define MOD (int)(1e9+9)
typedef long long ll;
using namespace std;

int d[100001][4];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    d[1][1]=d[2][2]=d[3][1]=d[3][2]=d[3][3]=1;
    for(int i=4;i<=100000;i++){
        for(int j=1;j<4;j++){
            ll tt=0;
            for(int k=1;k<4;k++){
                if(j==k) continue;
                tt+=d[i-j][k];
            }
            d[i][j]=tt%MOD;
        }
    }
    while(t--){
        int n;
        cin >> n;
        cout << ((d[n][1]+d[n][2])%MOD+d[n][3])%MOD << '\n';
    }
    return 0;
}