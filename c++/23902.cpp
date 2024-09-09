#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++){
        int n;
        ll d,c;
        cin >> n >> d;
        ll a[1000];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=n-1;i>-1;i--){
            a[i]*=d/a[i];
            d=a[i];
        }
        cout << "Case #" << tt+1 << ": " << a[0] << '\n';
    }
    return 0;
}