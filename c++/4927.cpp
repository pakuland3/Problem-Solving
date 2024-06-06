#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string c,ans[2]={". NOT!\n",". PASS\n"};
    int k=1;
    while(1){
        cin >> c;
        if(c[0]=='.') break;
        int sum[3]={0,};
        int d=0;
        bool l=0;
        for(int i=0;i<c.length()-1;i++){
            if(c[i]=='+' || c[i]=='*' || c[i]=='='){d++; if(c[i]=='*') l=1;}
            else sum[d]=(sum[d]+c[i]-'0')%9;
        }
        bool ind;
        if(l) ind=((sum[1]*sum[0])%9==sum[2]);
        else ind=((sum[1]+sum[0])%9==sum[2]);
        cout << k++ << ans[ind];
    }
    return 0;
}