#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool sieve[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve[1]=1;
    for(int i=2;i<1001;i++){
        if(sieve[i]) continue;
        for(int j=i*i;j<1000001;j+=i) sieve[j]=1;
    }
    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++){
        int n;
        cin >> n;
        int maxi=0;
        vector<ll> a(n),sum(n,0),mul(n,1);
        vector<vector<int>> cnt(n,vector<int> (13,0));
        vector<int> total(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            cin >> a[i];
            cnt[i][0]=!sieve[a[i]];
            for(int j=1;j*j<=a[i];j++) cnt[i][1]=(j*j==a[i]);
            for(int j=1;j*j*j<=a[i];j++) cnt[i][2]=(j*j*j==a[i]);
            for(int j=1;j*j*j*j<=a[i];j++) cnt[i][3]=(j*j*j*j==a[i]);
            int tmp=a[i];
            while(tmp){
                sum[i]+=tmp%10;
                tmp/=10;
            }
            cnt[i][4]=(a[i]%sum[i]==0);
            tmp=a[i];
            while(tmp){
                mul[i]*=tmp%10;
                tmp/=10;
            }
            if(mul[i]!=0) cnt[i][5]=(a[i]%mul[i]==0);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(a[i]!=a[j]){
                    cnt[i][6]+=(a[i]%a[j]==0 && cnt[i][6]==0);
                    cnt[i][7]+=(a[j]%a[i]==0 && cnt[i][7]==0);
                    cnt[i][8]+=(a[i]==a[j]*a[j] && cnt[i][8]==0);
                    cnt[i][9]+=(a[i]==a[j]*a[j]*a[j] && cnt[i][9]==0);
                    if(a[j]<32) cnt[i][10]+=(a[i]==a[j]*a[j]*a[j]*a[j] && cnt[i][10]==0);
                    if(mul[j]!=0) cnt[i][11]+=(a[i]%mul[j]==0 && cnt[i][11]==0);
                    cnt[i][12]+=(a[i]%sum[j]==0 && cnt[i][12]==0);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<13;j++) total[i]+=cnt[i][j];
            maxi=max(maxi,total[i]);
        }
        for(int i=0;i<n;i++) if(total[i]==maxi) ans.push_back(a[i]);
        sort(ans.begin(),ans.end());
        cout << "DATA SET #" << tt+1 << '\n';
        for(int i=0;i<ans.size();i++) cout << ans[i] << '\n';
    }
    return 0;
}