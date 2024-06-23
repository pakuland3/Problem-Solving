#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    bitset<20> bs;
    int m;
    cin >> m;
    while(m--){
        string s;
        int c;
        cin >> s;
        if(s!="all" && s!="empty") cin >> c;
        if(s=="add") bs[--c]=1;
        else if(s=="remove") bs[--c]=0;
        else if(s=="check") cout << bs[--c] << '\n';
        else if(s=="toggle") bs[c]=!bs[--c];
        else if(s=="all") bs=1048575;
        else bs.reset();
    }
    return 0;
}