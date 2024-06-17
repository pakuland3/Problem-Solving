#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,ini;
        cin >> n;
        int se=0,so=0;
        while(n--){
            cin >> ini;
            if(ini%2) so+=ini;
            else se+=ini;
        }
        if(se>so) cout << "EVEN";
        else if(se<so) cout << "ODD";
        else cout << "TIE";
        cout << '\n';
    }
    return 0;
}