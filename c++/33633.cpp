#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[205000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    // auto s=chrono::high_resolution_clock::now();
    if(n==1 || n==2 || n==3 || n==4){
        cout << "1\n";
        cout << (n>1?2:1)*(n>2?2:1)*(n>3?2:1);
        return 0;
    }
    int cnt=1;
    a[0]=8;
    for(int i=4;i<n;i++){
        int c=cnt;
        for(int j=0;j<c;j++){
            ll t=(a[j]-1)/3;
            if(a[j]%3==1 && t&1) a[cnt++]=t;
            a[j]<<=1;
        }
    }
    sort(a,a+cnt);
    cout << cnt << '\n';
    for(int i=0;i<cnt;i++) cout << a[i] << '\n';
    // auto e=chrono::high_resolution_clock::now();
    // cout << chrono::duration_cast<chrono::milliseconds>(e-s).count();
    return 0;
}