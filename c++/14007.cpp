#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int a[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int res=n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[j-1]) break;
            bool c=(a[j]>a[j-1] && a[j-1]>a[j-2])|(a[j]<a[j-1] & a[j-1]<a[j-2]);
            if(j>i+1 && c) break;
            res++;
        }
    }
    cout << res;
    return 0;
}