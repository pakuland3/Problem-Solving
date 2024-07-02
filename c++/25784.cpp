#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b==c || b+c==a || a+c==b) cout << 1;
    else if(a*b==c || b*c==a || a*c==b) cout << 2;
    else cout << 3;
    return 0;
}