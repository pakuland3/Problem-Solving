#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; if(n==0){cout << "NO"; return 0;}
    bool b=true;
    while(n>0){
        if(b){
            if(n%3==0) n/=3;
            else{n--;b=false;}
        }
        else{
            if(n%3==0){n/=3;b=true;}
            else{cout << "NO"; return 0;}
        }
    }
    cout << "YES";
    return 0;
}