#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n),pfx(n),sfx(n);
    for(int &t:a) cin >> t;
    for(int i=0;i<n;i++){
        pfx[i]=a[i];
        sfx[n-i-1]=a[n-i-1];
        if(i==0) continue;
        if(pfx[i-1]>0) pfx[i]+=pfx[i-1];
        if(sfx[n-i]>0) sfx[n-i-1]+=sfx[n-i];
    }
    for(int i=0;i<n;i++) cout << pfx[i]+sfx[i]-a[i] << ' ';
    return 0;
}