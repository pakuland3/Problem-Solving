#include <bits/stdc++.h>
using namespace std;

int n,cntofAll=0,possible=0;
bool h[100][100][2]={0,},r[100][100][2]={0,},c[100][100][2]={0,},block[100][100][100];
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){h[i][j][0]=s[j]-'0'; if(h[i][j][0]) cntofAll++;}
    }
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){r[i][j][0]=s[j]-'0'; if(r[i][j][0]) cntofAll++;}
    }
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){c[i][j][0]=s[j]-'0'; if(c[i][j][0]) cntofAll++;}
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++){
        if(h[j][k][0] && r[i][k][0] && c[i][j][0]){
            if(!h[j][k][1]){possible++; h[j][k][1]=1;}
            if(!r[i][k][1]){possible++; r[i][k][1]=1;}
            if(!c[i][j][1]){possible++; c[i][j][1]=1;}
            block[i][j][k]=1;
        }
        else block[i][j][k]=0;
    }
    if(possible!=cntofAll){cout << "NO"; return 0;}
    cout << "YES\n";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        for(int k=0;k<n;k++) cout << block[i][j][k];
        cout << '\n';
    }
    return 0;
}