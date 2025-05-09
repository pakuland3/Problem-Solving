#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n/2+n%2;i++) cout << 2*i+1 << ' ';
    for(int i=0;i<n/2;i++) cout << n-n%2-i*2 << ' ';
    return 0;
}