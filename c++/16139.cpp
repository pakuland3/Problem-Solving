#include <bits/stdc++.h>
using namespace std;

string s;
int q,l,r;
char c;
int arr[200000][26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(arr,0,sizeof(arr));
    cin >> s >> q;
    arr[0][s[0]-'a']++;
    for(int i=1;i<s.length();i++) for(int j=0;j<26;j++){
        if(s[i]-'a'==j) arr[i][j]=arr[i-1][j]+1;
        else arr[i][j]=arr[i-1][j];
    }
    while(q--){
        cin >> c >> l >> r;
        if(l==0) cout << arr[r][c-'a'];
        else cout << arr[r][c-'a']-arr[l-1][c-'a'];
        cout << '\n';
    }
    return 0;
}