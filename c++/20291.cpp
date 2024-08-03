#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    map<string,int> m;
    while(n--){
        string a,b("");
        cin >> a;
        int i=a.length()-1;
        while(a[i]!='.') i--;
        i++;
        while(i!=a.length()) b+=a[i++];
        auto it=m.find(b);
        if(it!=m.end()) m[b]++;
        else m[b]=1;
    }
    for(auto it=m.begin();it!=m.end();it++){
        cout << it->first << ' ' << it->second << '\n';
    }
    return 0;
}