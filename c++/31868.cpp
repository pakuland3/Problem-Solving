#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<n;i++) k/=2;
    cout << k;
    return 0;
}