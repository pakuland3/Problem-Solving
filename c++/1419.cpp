#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int l,r,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> l >> r >> k;
    if(k==2){
        l=l>3?l:3;
        if(r<l) cout << 0;
        else cout << r-l+1;
    }
    if(k==3){
        l=l>6?l+3-l%3:6;
        if(r<l) cout << 0;
        else cout << r/3-l/3+1;
    }
    if(k==4){
        l=l>10?l+l%2:10;
        if(r<l) cout << 0;
        else cout << r/2-l/2+1-(l<14);
    }
    if(k==5){
        l=l>15?l+5-l%5:15;
        if(r<l) cout << 0;
        else cout << r/5-l/5+1;
    }
    return 0;
}