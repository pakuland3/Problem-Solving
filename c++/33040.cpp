#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int h,w,c,d;
    cin >> h >> w >> c >> d;
    if(h*(h-1)/2>d){
        cout << -1;
        return 0;
    }
    int r=d-h*(h-1)/2;
    if(r/h+h-1>w || (r%h && r/h+h>w)){
        cout << -1;
        return 0;
    }
    for(int i=0;i<h;i++){
        int j;
        for(j=0;j<i+r/h+(i>=h-r%h);j++) cout << "9 ";
        for(;j<w;j++) cout << "1 ";
        cout << '\n';
    }
    return 0;
}