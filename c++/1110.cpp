#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    char c[2]={'0','0'};
    vector<int> a;
    cin >> n;
    a.push_back(n);
    while(1){
        bool b=0;
        if(n<10) c[0]=c[1]=n+'0';
        else{
            c[1]=(n/10+n%10)%10+'0';
            c[0]=n%10+'0';
        }
        n=c[0]*10+c[1]-11*'0';
        for(int i=0;i<a.size();i++){
            if(a[i]==n){
                b=1;
                break;
            }
        }
        if(b) break;
        a.push_back(n);
    }
    cout << a.size();
    return 0;
}