#include <bits/stdc++.h>
using namespace std;

int t;
int n,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int tt=0;tt<t;tt++){
        cin >> n >> k;
        string s("");
        for(int i=0;i<k;i++){
            char c=97+i;
            s+=c;
        }
        for(int i=0;i<n;i++){
            cout << s;
        }
        cout << '\n';
    }
}