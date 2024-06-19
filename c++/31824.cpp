#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    unordered_map<string, string> um;
    for(int i=0;i<n;i++){
        string a,b;
        cin >> a >> b;
        um[a]=b;
    }
    for(int j=0;j<m;j++){
        string d;
        cin >> d;
        bool b=0;
        for(int i=0;i<d.length();i++){
            string c("");
            c+=d[i];
            if(um.find(c)!=um.end()){cout << um[c]; b=1;}
            for(int k=i+1;k<d.length();k++){
                c+=d[k];
                if(um.find(c)!=um.end()){cout << um[c]; b=1;}
            }
        }
        if(!b) cout << -1;
        cout << '\n';
    }
    return 0;
}