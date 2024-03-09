#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int f[2001][2001][2]={0,};//0 -> horizontal
char c[2];                //1 -> vertical
bool ind;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k >> c[0];
    
    for(int i=1;i<n;i++){
        ind=i%2;
        cin >> c[ind];
        if(c[ind]=='B'){
            
        }
    }
    return 0;
}