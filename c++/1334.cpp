#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string a;

void add(int idx){
    int c=1;
    for(int i=idx;i>=0;i--){
        if(a[i]!='9' && c){
            a[i]++;
            c=0;
        }
        if(a[i]=='9' && c) a[i]='0';
    }
    if(c){
        a.push_back('0');
        for(int i=a.length()-1;i>0;i--) a[i]=a[i-1];
        a[0]='1';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a;
    add(a.length()-1);
    int idx=0;
    while(1){
        int p=1;
        for(int j=0;j<a.length()/2;j++) if(a[j]!=a[a.length()-1-j]) p=0;
        if(p){
            cout << a;
            return 0;
        }
        if(a[idx]<a[a.length()-1-idx]) add(a.length()-idx-2);
        a[a.length()-1-idx++]=a[idx];
    }
    return 0;
}