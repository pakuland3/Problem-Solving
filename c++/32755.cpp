#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int cnt[501];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n==2){
        cout << 1;
        exit(0);
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        cnt[a]++; cnt[b]++;
    }
    int c=0;
    for(int i=1;i<=n;i++) if(cnt[i]==1) c++;
    cout << n-(c==n-1?1:0);
    return 0;
}