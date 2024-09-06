#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int i=0,res=0;
    string a;
    cin >> a;
    for(;i<a.length();i++){
        if(a[i]==')') break;
        if(a[i]=='@') res++;
    }
    cout << res << ' ';
    res=0;
    for(;i<a.length();i++) if(a[i]=='@') res++;
    cout << res;
    return 0;
}