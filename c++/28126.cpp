#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    int a=0,b=0,c=0;
    cin >> n;
    for(int i=0;i<n;i++){
        char t;
        cin >> t;
        if(t=='R') a++;
        else if(t=='U') b++;
        else c++;
    }
    cin >> k;
    int res=0;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        int t=min(min(x,y),c);
        x-=t;
        y-=t;
        res+=(a>=x && b>=y);
    }
    cout << res;
    return 0;
}