#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> arr(n);
    for(string &a:arr) cin >> a;
    sort(arr.begin(),arr.end(),[](string &a, string &b)->bool{
        return stoul(a+b)>stoul(b+a);
    });
    for(int i=0;i<n;i++){
        if(i==0 && stoul(arr[i])==0){cout << 0; return 0;}
        cout << arr[i];
    }
    return 0;
}