#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(9); for(int i=0;i<10;i++) p[i]=pow(2,i);
    vector<int> a(8); for(int i=0;i<8;i++) a[i]=i;
    while(n--){
        int b;
        cin >> b;
        auto it=upper_bound(p.begin(),p.end(),b)-1;
        int rep=b-*it;
        int i,j;
        i=it-p.begin();
        j=lower_bound(p.begin(),p.end(),rep)-p.begin();
        if(p[j]==b-*it) swap(a[i],a[j]);
    }
    int k;
    cin >> k;
    cout << a[k];
    return 0;
}