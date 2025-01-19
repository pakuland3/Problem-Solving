#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(ll a){
    ll cnt=sqrt(a);
    for(int i=2;i<=cnt;i++) if(a%i==0) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,j;
    int cnt=0;
    cin >> n >> n >> j;
    vector<vector<ll>> a(j);
    int tt=1<<(n-2);
    for(int i=0;i<tt && cnt!=j;i++){
        bitset<16> bs(i);
        bool p=1;
        vector<ll> tmp;
        for(int jj=2;jj<11;jj++){
            ll sum=1;
            ll d=jj;
            for(int k=0;k<n-2;k++){
                if(bs[k]) sum+=d;
                d*=(ll)jj;
            }
            sum+=d;
            if(solve(sum)){
                p=0;
                break;
            }
            tmp.push_back(sum);
        }
        if(!p) continue;
        a[cnt].push_back(i);
        for(int jj=0;jj<9;jj++) a[cnt].push_back(tmp[jj]);
        cnt++;
    }
    cout << "Case #1:\n";
    for(int i=0;i<j;i++){
        vector<ll> s;
        for(int jj=1;jj<10;jj++){
            ll ccc=sqrt(a[i][jj]);
            for(int k=2;k<=ccc;k++){
                if(a[i][jj]%k==0){
                    s.push_back(k);
                    break;
                }
            }
        }
        bitset<16> bs(a[i][0]);
        cout << '1';
        for(int k=n-3;k>=0;k--) cout << bs[k];
        cout << "1 ";
        for(auto it=s.begin();it!=s.end();it++) cout << *it << ' ';
        cout << '\n';
    }
    return 0;
}