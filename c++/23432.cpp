#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll a,b;
    cin >> n >> a;
    cout << a << ' ';
    for(int i=1;i<n;i++){
        cin >> b;
        b=(a/b+1)*b;
        cout << b << ' ';
        a=b;
    }
    return 0;
}