#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    int cur=a[0],ind=0,k=1;
    for(int i=1;i<n;i++){
        if(a[i]>=cur){
            cur=a[i];
            k=max(k,i-ind);
            ind=i;
        }
        if(i==n-1 && a[i]<cur) k=max(k,n-ind);
    }
    cout << k;
    return 0;
}