#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n==0){
        cout << 0;
        return 0;
    }
    vector<int> a(n);
    for(int &t:a) cin >> t;
    sort(a.begin(),a.end());
    int k=round((double)n*3.0/20.0);
    double sum=0;
    for(int i=k;i<n-k;i++) sum+=a[i];
    int res=round(sum/(double)(n-2*k));
    cout << res;
    return 0;
}