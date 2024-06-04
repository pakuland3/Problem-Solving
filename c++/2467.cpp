#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,left,right,dif=2e9+1;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    int l=0,r=n-1;
    while(l!=r){
        int sum=a[l]+a[r];
        if(abs(sum)<dif){
            left=l;
            right=r;
            dif=abs(sum);
        }
        if(sum>=0) r--;
        else l++;
    }
    cout << a[left] << ' ' << a[right];
    return 0;
}