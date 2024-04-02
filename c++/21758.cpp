#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<int> arr(n),prs(n); cin >> arr[0]; prs[0]=arr[0]; int maxi[2]={arr[0],0};
    for(int i=1;i<n;i++){
        cin >> arr[i]; if(arr[i]>maxi[0]){maxi[0]=arr[i];maxi[1]=i;} prs[i]=prs[i-1]+arr[i];
    }
    int ans=(maxi[1]-1>=0)?prs[maxi[1]]-prs[0]+prs[n-2]-prs[maxi[1]-1]:0;
    for(int i=1;i<n-1;i++){
        ans=max(ans,2*prs[n-1]-prs[0]-arr[i]-prs[i]);
        ans=max(ans,prs[n-2]-arr[n-1-i]+prs[n-2-i]);
    }
    cout << ans;
    return 0;
}