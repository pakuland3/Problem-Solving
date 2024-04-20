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
        l=l>6?l:6;
        while(l%3!=0 || r%3!=0){
            if(l%3!=0) l++;
            if(r%3!=0) r--;
        }
        if(r<l) cout << 0;
        else cout << (r-l)/3+1;
    }
    if(k==4){
        l=l>10?l:10;
        while(l%2!=0 || r%2!=0){
            if(l%2!=0) l++;
            if(r%2!=0) r--;
        }
        if(r<l) cout << 0;
        else{
            int ans=(r-l)/2+1;
            if(l<14 && r>10) ans--;
            cout << ans;
        }
    }
    if(k==5){
        l=l>15?l:15;
        while(l%5!=0 || r%5!=0){
            if(l%5!=0) l++;
            if(r%5!=0) r--;
        }
        if(r<l) cout << 0;
        else cout << (r-l)/5+1;
    }
    return 0;
}