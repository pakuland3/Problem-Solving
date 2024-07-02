#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(10);
    cout << fixed;
    int n;
    cin >> n;
    vector<double> c(n),w(n);
    for(double &a:c) cin >> a;
    for(double &a:w) cin >> a;
    double ans=0;
    for(int i=0;i<n;i++) ans+=abs(c[i]*w[0]/c[0]-w[i]);
    for(int i=1;i<n;i++){
        double d=w[i]/c[i];
        double tmp=0;
        for(int i=0;i<n;i++) tmp+=abs(d*c[i]-w[i]);
        ans=min(ans,tmp);
    }
    cout << ans;
    return 0;
}