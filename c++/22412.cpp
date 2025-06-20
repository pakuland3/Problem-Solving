#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(string s){
    if(s.length()<3){
        // cout << "No";
        // exit(0);
        return 0;
    }
    int c[3]={0,};
    for(int i=0;i<s.length();i++) c[s[i]-'A']++;
    while(s.length()!=3){
        int m=min(c[0],min(c[1],c[2]));
        if((m==c[0])+(m==c[1])+(m==c[2])>1){
            // cout << "No";
            // exit(0);
            return 0;
        }
        int mini=(c[0]<min(c[1],c[2])?0:(c[1]<c[2]?1:2));
        int l=s.length();
        for(int i=2;i<s.length();i++){
            if(s[i]=='C' && s[i-1]=='B' && s[i-2]=='A'){
                s[i]='A'+mini;
                for(int j=0;j<3;j++) if(j!=mini) c[j]--;
                s.erase(i-2,2);
            }
        }
        if(l==s.length()){
            // cout << "No";
            // exit(0);
            return 0;
        }
    }
    if(s[0]=='A' && s[1]=='B' && s[2]=='C'){
        // cout << "Yes";
        return 1;
    }
    else{
        // cout << "No";
        return 0;
    }
}

void p(string &a, int n){
    if(n==7){
        if(solve(a)) cout << a << '\n';
        return;
    }
    for(int i=0;i<3;i++){
        a+='A'+i;
        p(a,n+1);
        a.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string t="";
    p(t,0);
    return 0;
}