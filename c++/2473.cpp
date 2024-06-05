#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &t:a) cin >> t;
    sort(a.begin(),a.end());
    int left,mid,right;
    ll dif=3e9+1;
    for(int i=0;i<n-2;i++){
        int cur=i;
        int l=i+1;
        int r=n-1;
        while(l<r){
            ll sum=a[cur]+a[l]+a[r];
            if(abs(sum)<dif){
                dif=abs(sum);
                left=cur;
                mid=l;
                right=r;
            }
            if(sum>=0) r--;
            else l++;
        }
    }
    cout << a[left] << ' ' << a[mid] << ' ' << a[right];
    return 0;
}