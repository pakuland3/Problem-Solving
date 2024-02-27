#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,l; cin >> n >> l;
    ll a=0;
    if(n/l-l/2>3) a=n/l-l/2-3; 
    long long sum=(a*2+l-1)*l/2;
    while(sum!=n && l<=100){
        if(sum>n){
            l++;
            if(n/l-l/2>3) a=n/l-l/2-3;
            else a=0;
        }
        else a++;
        sum=(a*2+l-1)*l/2;
    }
    if(sum!=n){cout << -1;return 0;}
    for(int i=0;i<l;i++) cout << a+i << ' ';
    return 0;
}