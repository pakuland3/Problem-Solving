#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int s,k; cin >> s >> k;
    long long ans=1;
    for(int i=0;i<s%k;i++) ans*=s/k+1;
    for(int i=0;i<k-s%k;i++) ans*=s/k;
    cout << ans;
    return 0;
}