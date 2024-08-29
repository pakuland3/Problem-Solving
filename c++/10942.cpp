#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,m,s,e;
int a[2000];
bool dp[2000][2000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        for(int j=0;i+j<n;j++){
            if(i==0) dp[j][j]=1;
            else if(i==1 && a[j]==a[j+1]) dp[j][j+1]=1;
            else if(i>1 && dp[j+1][i+j-1] && a[j]==a[i+j]) dp[j][i+j]=1;       
        }
    }
    cin >> m;
    while(m--){
        cin >> s >> e;
        cout << dp[(--s)][(--e)] << '\n';
    }
    return 0;
}