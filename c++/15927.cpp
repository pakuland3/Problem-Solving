#include <bits/stdc++.h>
using namespace std;

string N;

bool isPalindrome(){
    for(int i=0;i<N.length()/2;i++){
        if(N[i]!=N[N.length()-(i+1)]) return false;
    }
    return true;
}

bool isImpossible(){
    for(int i=1;i<N.length();i++){
        if(N[0]!=N[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    if(isImpossible()){cout << -1; return 0;}
    if(isPalindrome()){cout << N.length()-1; return 0;}
    cout <<  N.length();
    return 0;
}