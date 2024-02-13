#include <bits/stdc++.h>
using namespace std;
int arr[100000];
bool p=false;
int t=0;
string s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    for(int i=0;i<s.length();i++){if(s[i]=='0'){p=true;}t+=s[i]-'0';arr[i]=s[i]-'0';}
    if(t%3==0 && p){
        sort(arr,arr+s.length(),[](int l,int r)-> bool {return l>r;});
        for(int i=0;i<s.length();i++) cout << arr[i];
    }
    else cout << -1;
}