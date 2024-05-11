#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,c;
    cin >> n >> c;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    sort(h.begin(),h.end());
    int l=1,r=h[n-1]-h[0],mid;
    while(l<=r){
        mid=(l+r)/2;
        int cnt=1,cur=h[0];
        for(int i=1;i<n;i++) if(h[i]-cur>=mid){cnt++; cur=h[i];}
        if(cnt>=c) l=mid+1;
        else r=mid-1;
    }
    cout << r;
    return 0;
}