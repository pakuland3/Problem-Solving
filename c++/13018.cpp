#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    if(n==k){
        cout << "Impossible";
        exit(0);
    }
    if(k==n-1){
        for(int i=0;i<n;i++) cout << i+1 << ' ';
        exit(0);
    }
    vector<int> a(n+1);
    for(int i=2;i<k+2;i++) a[i]=i;
    for(int i=k+3;i<=n;i++) a[i]=i-1;
    a[k+2]=1;
    a[1]=n;
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
    return 0;
}