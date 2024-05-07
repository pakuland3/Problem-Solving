#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans=0;
    string a[8];
    for(int i=0;i<8;i++) cin >> a[i];
    for(int i=0;i<8;i++) for(int j=0;j<8;j++){
        if((i+j)%2==0 && a[i][j]=='F') ans++; 
    }
    cout << ans;
    return 0;
}