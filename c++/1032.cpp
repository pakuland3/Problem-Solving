#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string a,b;
    cin >> a;
    for(int i=1;i<n;i++){
        cin >> b;
        for(int j=0;j<b.length();j++) if(a[j]!=b[j]) a[j]='?';
    }
    cout << a;
    return 0;
}