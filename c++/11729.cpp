#include <bits/stdc++.h>
using namespace std;

int n;

void h(int n, int from, int to, int other){
    if(n==1){cout << from << ' ' << to << '\n';return;}
    h(n-1,from,other,to);
    cout << from << ' ' << to <<'\n';
    h(n-1,other,to,from);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cout << int64_t(pow(2,n))-1 << '\n';
    h(n,1,3,2);
    return 0;
}