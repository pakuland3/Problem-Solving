#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a;
    int b[1001];
    cin >> a; b[0]=a[0]-'0';
    for(int i=1;i<a.length();i++) b[i]=a[i]-'0'+b[i-1];
    for(int i=a.length()-a.length()%2;i>0;i-=2){
        for(int j=0;j<a.length()-i+1;j++){
            int c=b[j+i/2-1]-(j!=0?b[j-1]:0);
            int d=b[j+i-1]-(j+i/2!=1?b[j+i/2-1]:0);
            if(c==d){
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}