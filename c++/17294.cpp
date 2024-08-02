#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a;
    cin >> a;
    int d=a[min((int)a.length()-1,1)]-a[0];
    for(int i=2;i<a.length();i++){
        if(d!=a[i]-a[i-1]){
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
            return 0;
        }
    }
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    return 0;
}