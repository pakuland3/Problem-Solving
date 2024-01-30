#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;
int n;
string p;

ll isPrime(ll n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int tt=0;tt<t;tt++){
        cin >> n >> p;
        int cnt=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(i!=0){
                for(int j=0;j<=9;j++){
                    string tmp=p;
                    string onei=to_string(j);
                    tmp[i]=onei[0];
                    ll ans=isPrime(stoi(tmp));
                    if(ans!=-1){
                        cout << tmp << ' ' << ans << '\n';
                        cnt++;
                    }
                    if(cnt==n) flag=true;
                    if(flag) break;
                }
            }
            else{
                for(int j=1;j<=9;j++){
                    string tmp=p;
                    string onei=to_string(j);
                    tmp[i]=onei[0];
                    ll ans=isPrime(stoi(tmp));
                    if(ans!=-1){
                        cout << tmp << ' ' << ans << '\n';
                        cnt++;
                    }
                    if(cnt==n) flag=true;
                    if(flag) break;
                }
            }
            if(flag) break;
        }
    }
    return 0;
}