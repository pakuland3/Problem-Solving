#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<double> c(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        c[i]=min(a,b);
    }
    ll l;
    cin >> l;
    sort(c.begin(),c.end());
    double sum=0;
    int idx;
    for(int i=0;i<n;i++){
        if(sum+c[i]>l){
            idx=i;
            if(i==0){
                cout << 1;
                return 0;
            }
            break;
        }
        sum+=c[i];
        if(i==n-1){
            cout << n;
            return 0;
        }
    }
    sum-=c[idx-1]/2;
    if(sum+c[idx]/2>=l) cout << idx;
    else cout << idx+1;
    return 0;
}