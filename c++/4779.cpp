#include <bits/stdc++.h>
using namespace std;

int n;

void solve(int n){
    if(n==1){cout << '-';return;}
    solve(n/3);
    for(int i=0;i<n/3;i++) cout << ' ';
    solve(n/3);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n){
        solve(pow(3,n));
        cout << '\n';
    }
}