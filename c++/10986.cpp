#include <bits/stdc++.h>
using namespace std;

int n,m;
long long ans=0;
int cnt[1001]={0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int arr[2]; cin >> arr[0]; arr[0]%=m;
    if(arr[0]==0) ans++;
    cnt[arr[0]]++;
    bool ind;
    for(int i=1;i<n;i++){
        ind=i%2;
        cin >> arr[ind]; arr[ind]=(arr[ind]+arr[!ind])%m;
        if(arr[ind]==0) ans++;
        ans+=cnt[arr[ind]];
        cnt[arr[ind]]++;
    }
    cout << ans;
    return 0;
}