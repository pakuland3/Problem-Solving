#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    while(getline(cin,s)){
        if(s[0]=='#') break;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                int stsz=st.size();
                while(stsz--){
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else st.push(s[i]);
            if(i==s.length()-1) while(!st.empty()){
                cout << st.top();
                st.pop();
            }
        }
        cout << '\n';
    }
    return 0;
}