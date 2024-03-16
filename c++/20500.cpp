#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int n;
ll o[1515][3]={0,};
ll f[1515][3]={0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    o[0][1]=1; f[0][2]=1;
    cin >> n;
    for(int i=1;i<n;i++){
        o[i][0]=(f[i-1][2]+o[i-1][2])%MOD;
        o[i][1]=(f[i-1][0]+o[i-1][0])%MOD;
        o[i][2]=(f[i-1][1]+o[i-1][1])%MOD;
        f[i][0]=(f[i-1][1]+o[i-1][1])%MOD;
        f[i][1]=(f[i-1][2]+o[i-1][2])%MOD;
        f[i][2]=(f[i-1][0]+o[i-1][0])%MOD;
    }
    cout << f[n-1][0];
    return 0;
}