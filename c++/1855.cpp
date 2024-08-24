#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int dx[]={1,-1};
    int idx[]={0,n-1};
    for(int i=0;i<n;i++) for(int j=0;j<s.length()/n;j++) cout << s[j*n+idx[j%2]+dx[j%2]*i];
    return 0;
}