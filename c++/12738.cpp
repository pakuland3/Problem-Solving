#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,a;
    cin >> n;
    vector<int> b;
    cin >> a;
    b.push_back(a);
    for(int i=1;i<n;i++){
        cin >> a;
        auto it=lower_bound(b.begin(),b.end(),a);
        if(it==b.end()) b.push_back(a);
        else *it=a;
    }
    cout << b.size();
    return 0;
}