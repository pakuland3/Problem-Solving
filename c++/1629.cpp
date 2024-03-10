#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a,b,c;

ll getPow(ll bb){
    if(bb==1) return a;
    ll tmp;
    if(bb%2!=0){
        tmp=getPow((bb-1)/2)%c;
        tmp=((tmp*tmp)%c)*a; tmp%=c;
    }
    else{
        tmp=getPow(bb/2)%c;
        tmp=(tmp*tmp)%c;
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c; a%=c;
    cout << getPow(b);
    return 0;
}