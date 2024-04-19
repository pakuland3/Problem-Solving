#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    string firstL("`1234567890-="),secondL("QWERTYUIOP[]\\"),thirdL("ASDFGHJKL;'"),fourthL("ZXCVBNM,./");
    while(getline(cin,s)){
        int l=s.length();
        for(int i=0;i<l;i++){
            int ind=firstL.find(s[i]);
            if(ind!=string::npos){
                s[i]=firstL[ind-1];
                continue;
            }
            ind=secondL.find(s[i]);
            if(ind!=string::npos){
                s[i]=secondL[ind-1];
                continue;
            }
            ind=thirdL.find(s[i]);
            if(ind!=string::npos){
                s[i]=thirdL[ind-1];
                continue;
            }
            ind=fourthL.find(s[i]);
            if(ind!=string::npos){
                s[i]=fourthL[ind-1];
                continue;
            }
        }
        cout << s << '\n';
    }
    return 0;
}