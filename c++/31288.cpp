#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        if(n==1){
            int cur=s[0]-'0';
            if(cur!=6) cout << "6 3\n";
            else cout << "9 3\n";
            continue;
        }
        int sum=0;
        for(int i=0;i<n;i++) sum+=s[i]-'0';
        for(int i=0;i<n;i++){
            int p=3-(sum-(s[i]-'0'))%3;
            for(int j=0;j<i;j++) cout << s[j];
            if(p!=s[i]-'0'){
                if(i==0 && p==0 && s[i]-'0'!=3) cout << 3;
                else if(i==0 && p==0 && s[i]-'0'!=6) cout << 6;
                else cout << p;
            }
            else cout << p+3;
            for(int j=i+1;j<n;j++) cout << s[j];
            cout << " 3\n";
        }
    }
    return 0;
}