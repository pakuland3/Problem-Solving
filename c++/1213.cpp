#include <bits/stdc++.h>
using namespace std;

string s;
int arr[26];
bool f=false;
int cnt=0;
char c=' ';
string ans("");

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    for(int i=0;i<s.length();i++) arr[s[i]-'A']++;
    if(s.length()%2==0){
        for(int i=0;i<26;i++) if(arr[i]%2!=0){f=true;break;}
    }
    else{
        for(int i=0;i<26;i++) if(arr[i]%2!=0){cnt++;}
    }
    if(cnt>1) f=true;
    if(f){cout << "I'm Sorry Hansoo";return 0;}
    for(int i=0;i<26;i++){
        if(arr[i]%2==0) for(int j=0;j<arr[i]/2;j++){cout << (char)(i+'A');ans+=i+'A';}
        else{c=i+'A';for(int j=0;j<arr[i]/2;j++){cout << (char)(i+'A');ans+=i+'A';}}
    }
    if(c!=' '){
        cout << c;
        for(int i=ans.length()-1;i>-1;i--) cout << ans[i];
    }
    else for(int i=ans.length()-1;i>-1;i--) cout << ans[i];
}