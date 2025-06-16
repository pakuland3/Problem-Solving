#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n%2==0 || n%5==0){
        cout << -1;
        return 0;
    }
    int r=1%n;
    int t=1%n;
    for(int i=0;;i++){
        if(r==0){
            cout << i+1;
            exit(0);
        }
        t=(t*10)%n;
        r=(r+t)%n;
    }
    return 0;
}