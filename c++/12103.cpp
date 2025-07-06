#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,k;
int cnt[1000001][2];
int dp[1000001][2][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        cnt[i%k][a[i]&1]++;
    }
    for(int i=0;i<k;i++){
        if(i!=0){
            int z=dp[i-1][0][0]+cnt[i][1],o=dp[i-1][1][0]+cnt[i][0];
            if(z>o) dp[i][0][0]=o,dp[i][0][1]=1;
            else dp[i][0][0]=z;
            z-=cnt[i][1]-cnt[i][0];
            o-=cnt[i][0]-cnt[i][1];
            if(z>o) dp[i][1][0]=o,dp[i][1][1]=1;
            else dp[i][1][0]=z;
        }
        else dp[i][0][0]=cnt[i][1],dp[i][1][0]=cnt[i][0];
    }
    int s=0,b=dp[k-1][s][1];
    for(int i=k-1;i>=0;i--){
        for(int j=i;j<n;j+=k){
            if(s){
                if(b && a[j]&1) a[j]=0;
                if(!b && !(a[j]&1)) a[j]=1;
            }
            else{
                if(b && !(a[j]&1)) a[j]=1;
                if(!b && a[j]&1) a[j]=0; 
            }
        }
        if(i!=0){
            s=b;
            b=dp[i-1][s][1];
        }
    }
    cout << dp[k-1][0][0] << '\n';
    for(int t:a) cout << t << ' ';
    return 0;
}