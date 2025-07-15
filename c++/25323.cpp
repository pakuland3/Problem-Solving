#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[500001],b[500001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i],b[i]=a[i];
    sort(b,b+n);
    for(int i=0;i<n;i++){
        ll g=gcd(a[i],b[i]);
        ll c=a[i]/g,d=sqrt(c);
        if(c!=d*d){
            cout << "NO";
            exit(0);
        }
        c=b[i]/g,d=sqrt(c);
        if(c!=d*d){
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    return 0;
}