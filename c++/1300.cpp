#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll x,y;
    cin >> x >> y;
    cout << "2\n" << x*(y-1) << '\n' << y-x*y;
    return 0;
}