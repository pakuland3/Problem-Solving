#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int l=1;
    for(int &t:a){
        cin >> t;
        if(t==l) l++;
    }
    cout << n+1-l;
    return 0;
}