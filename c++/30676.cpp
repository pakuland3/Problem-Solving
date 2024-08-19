#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(619<n && n<781) cout << "Red";
    if(589<n && n<620) cout << "Orange";
    if(569<n && n<590) cout << "Yellow";
    if(494<n && n<570) cout << "Green";
    if(449<n && n<495) cout << "Blue";
    if(424<n && n<450) cout << "Indigo";
    if(379<n && n<425) cout << "Violet";
    return 0;
}