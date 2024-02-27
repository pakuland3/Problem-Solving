#include <bits/stdc++.h>
using namespace std;

int n;
long long ans=0;

bool check(int cnt, int ind, int arr[15]){
    //(cnt,ind) -> position
    //(i,arr[i])
    for(int i=0;i<cnt;i++){
        if(arr[i]==ind) return false;
        if(abs(i-cnt)==abs(arr[i]-ind)) return false;
    }
    return true;
}

void solve(int cnt, int arr[15]){
    if(cnt==n){ans++;return;}
    for(int i=0;i<n;i++){
        if(check(cnt,i,arr)){
            int tmp[15];
            for(int i=0;i<cnt;i++) tmp[i]=arr[i];
            tmp[cnt]=i;
            solve(cnt+1, tmp);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int arr[15]; memset(arr,0,sizeof(arr));
    solve(0,arr);
    cout << ans;
    return 0;
}