#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n==1){
        cout << "no";
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            ll k=i;
            int l=n/i;
            int d=1;
            for(int j=0;k<=l;j++,k*=i) if(k==l){d=0;}
            cout << (d?"no":"yes");
            return 0;
        }
    }
    cout << "yes";
    return 0;
}