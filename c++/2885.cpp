#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int p=0;
    for(;1<<p<n;p++);
    cout << (1<<p) << ' ';
    int res=0;
    while(n){
        if(1<<p<=n) n-=1<<p;
        p--;
        res++;
    }
    cout << res-1;
    return 0;
}