#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a,b;
    while(1){
        cin >> a;
        if(!a) break;
        int b=sqrt(a);
        while(a%b!=0) b--;
        a/=b;
        int l=2*a+2*b;
        cout << "Minimum perimeter is " << l << " with dimensions " << min(a,b) << " x " << max(a,b) << '\n';
    }
    return 0;
}