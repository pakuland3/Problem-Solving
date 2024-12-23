#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a,b;
        bool turn=0;
        while(n){
            int c=n%10;
            int m=n%2;
            a.push_back(c/2+(!turn)*m);
            b.push_back(c/2+turn*m);
            n/=10;
            if(m) turn^=1;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        while(a[i]==0 && i!=a.size()-1) i++;
        for(;i<a.size();i++) cout << a[i];
        cout << ' ';
        i=0;
        while(b[i]==0 && i!=b.size()-1) i++;
        for(;i<b.size();i++) cout << b[i];
        cout << '\n';
    }
    return 0;
}