#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,l,ci=0,ans=0; cin >> n >> l; vector<pair<int, int>> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(),arr.end(),[](pair<int, int> l, pair<int, int> r)->bool{
        return l.first<r.first;
    });
    for(int i=0;i<n;i++){
        if(arr[i].first<=ci){
            if(arr[i].second<ci) continue;
            int cnt=((arr[i].second-ci)%l==0 ? (arr[i].second-ci)/l:(arr[i].second-ci)/l+1);
            ans+=cnt;
            ci+=cnt*l;
        }
        else{
            int cnt=((arr[i].second-arr[i].first)%l==0 ? (arr[i].second-arr[i].first)/l:(arr[i].second-arr[i].first)/l+1);
            ans+=cnt;
            ci=arr[i].first+cnt*l;
        }
    }
    cout << ans;
    return 0;
}