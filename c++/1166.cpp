#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ld n,l,w,h,s=0,e=1e10,mid;
    int cnt=100;
    cin >> n >> l >> w >> h;
    cout << fixed; cout.precision(10);
    while(cnt--){
        mid=(s+e)/2;
        if((ll)(l/mid)*(ll)(w/mid)*(ll)(h/mid)<n) e=mid;
        else s=mid;
    }
    cout << mid;
    return 0;
}