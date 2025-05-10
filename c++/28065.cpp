#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int d[]={1,-1};
    int a=1;
    int dif=n-1;
    for(int i=0;i<n;i++,dif--){
        cout << a << ' ';
        a+=d[i%2]*dif;
    }
    return 0;
}