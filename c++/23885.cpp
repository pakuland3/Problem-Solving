#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    int x;
    int y;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    poi a[2]; int n,m;
    cin >> n >> m >> a[0].x >> a[0].y >> a[1].x >> a[1].y;
    if(a[0].x==a[1].x && a[0].y==a[1].y) cout << "YES";
    else if((a[0].x+a[0].y)%2!=(a[1].x+a[1].y)%2 || n==1 || m==1) cout << "NO";
    else cout << "YES";
    return 0;
}