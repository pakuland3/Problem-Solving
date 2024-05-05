#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n;
    vector<int> arr(n);
    for(int &a:arr) cin >> a;
    cin >> k;
    for(int i=0;i<k;i++) sort(arr.begin()+n/k*i,arr.begin()+n/k*(i+1));
    for(int &a:arr) cout << a << ' ';
    return 0;
}