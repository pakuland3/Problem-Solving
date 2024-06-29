#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    unordered_map<string,bool> um; 
    while(n--){
        string s;
        cin >> s;
        int rep=s.length();
        um.insert({s,1});
        for(int i=1;i<rep;i++){
            s.erase(s.end()-1);
            if(um.find(s)==um.end()) um.insert({s,1});
        }
    }
    int ans=0;
    while(m--){
        string s;
        cin >> s;
        if(um.find(s)!=um.end()) ans++;
    }
    cout << ans;
    return 0;
}