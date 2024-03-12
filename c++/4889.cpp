#include <bits/stdc++.h>
using namespace std;

string s;
int cnt,ans,n=1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1){
        cin >> s;
        cnt=0;
        ans=0;
        if(s[0]=='-') break;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{') cnt++;
            else{
                if(cnt>0) cnt--;
                else{
                    cnt++;
                    ans++;
                }
            }
        }
        cout << n++ << ". " << ans+(cnt+1)/2 << '\n';
    }
    return 0;
}