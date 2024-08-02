#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,ans=0;
    cin >> n;
    while(n--){
        string a;
        stack<char> s;
        cin >> a;
        for(int i=0;i<a.length();i++){
            if(!s.empty() && s.top()==a[i]) s.pop();
            else s.push(a[i]);
        }
        if(s.empty()) ans++;
    }
    cout << ans;
    return 0;
}