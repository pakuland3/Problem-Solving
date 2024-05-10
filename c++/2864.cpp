#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a,b,tmpa,tmpb;
    cin >> a >> b;
    tmpa=a; tmpb=b;
    for(int i=0;i<a.length();i++) if(tmpa[i]=='5') tmpa[i]='6';
    for(int i=0;i<b.length();i++) if(tmpb[i]=='5') tmpb[i]='6';
    for(int i=0;i<a.length();i++) if(a[i]=='6') a[i]='5';
    for(int i=0;i<b.length();i++) if(b[i]=='6') b[i]='5';
    cout << stoi(a)+stoi(b) << ' ' << stoi(tmpa) + stoi(tmpb);
    return 0;
}