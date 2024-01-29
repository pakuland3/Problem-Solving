#include <bits/stdc++.h>
using namespace std;

int a;
int b;
int n;
long long ans=0;

int main(){
    cin >> n;
    for(a=-n;a<=n;a++){
        if(a!=0){
            for(b=-n;b<=n;b++){
                if(abs(a+b)<=n) ans++;
            }
        }
    }
    cout << ans+(2*n+1)*(2*n+1);
}