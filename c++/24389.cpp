#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a;
    cin >> a;
    a^=-a;
    int res=0;
    for(int i=0;i<32;i++){
        res+=(((ll)(1<<i)&(ll)a)?1:0);
    }
    cout << res;
    return 0;
}