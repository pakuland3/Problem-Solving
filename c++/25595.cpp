#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    char a[100][100];
    int b;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin >> a[i][j];
        if(a[i][j]=='2') b=(i+j)%2;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j]=='1' && b==(i+j)%2){
        cout << "Kiriya";
        return 0;
    }
    cout << "Lena";
    return 0;
}