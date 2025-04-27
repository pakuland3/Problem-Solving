#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    if(c&1) cout << (a^b);
    else cout << a;
    return 0;
}