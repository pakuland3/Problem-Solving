#include <bits/stdc++.h>
using namespace std;

int n,f;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> f; n/=100; n*=100;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++){
        n+=10*i+j; if(n%f==0){cout << i << j; return 0;}
        n-=10*i+j;
    }
    return 0;
}