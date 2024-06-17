#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin >> n){
        if(n==0) break;
        vector<bool> a(50,0);
        int t;
        while(n--){
            for(int i=0;i<6;i++){cin >> t; a[t]=1;}
        }
        bool b=1;
        for(int i=1;i<50;i++) if(!a[i]){b=0; break;}
        if(b) cout << "Yes";
        else cout <<  "No";
        cout << '\n';
    }
    return 0;
}