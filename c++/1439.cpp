#include <bits/stdc++.h>
using namespace std;

string s;
int part[2]={0,};
int b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    b=s[0]-'0';
    for(int i=1;i<s.length();i++){
        if(b==0 && s[i]=='1'){part[0]++;b=1;}
        else if(b==1 && s[i]=='0'){part[1]++;b=0;}
        if(i==s.length()-1) part[s[i]-'0']++;
    }
    cout << min(part[0],part[1]);
}