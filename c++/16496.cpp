#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int r,c,k;
    cin >> r >> c >> k;
    if(r*c%2!=0){
        if(k>1) cout << 0;
        else cout << 1;
    }
    else cout << 1;
    return 0;
}