#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        string a;
        cin >> a;
        vector<string> c;
        for(int i=a.length()-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    swap(a[i],a[j]);
                    string d("");
                    for(int k=0;k<a.length();k++) d+=a[k];
                    sort(d.begin()+j+1,d.end());
                    c.push_back(d);
                    swap(a[i],a[j]);
                }
            }
        }
        sort(c.begin(),c.end());
        if(c.empty()) cout << a << '\n';
        else cout << c[0] << '\n';
    }
    return 0;
}