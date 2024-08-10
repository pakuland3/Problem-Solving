#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a[10][10];
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) cin >> a[i][j];
    for(int i=0;i<10;i++){
        bool b=1,c=1;
        for(int j=0;j<10;j++){
            if(a[0][i]!=a[j][i]) b=0;
            if(a[i][0]!=a[i][j]) c=0;
        }
        if(b || c){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}