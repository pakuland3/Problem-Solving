#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string l;
    int r;
    bool e8[10]={0,};
    int cnt=0;
    int pot[10];
    for(int i=0;i<10;i++) pot[i]=pow(10,i); 
    cin >> l >> r;
    for(int i=0;i<l.length();i++){
        if(l[i]=='8'){
            e8[l.length()-(i+1)]=1;
            cnt++;
        }
    }
    int nl=stoi(l);
    int diff=r-nl;
    for(int i=0;i<l.length();i++){
        nl-=(l[i]-'0')*pot[l.length()-(i+1)];
        if(e8[l.length()-(i+1)] && nl+diff>=pot[l.length()-(i+1)]) cnt--;
    }
    cout << cnt;
}