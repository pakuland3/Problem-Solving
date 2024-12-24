#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(1){
        string a;
        cin >> a;
        if(a.length()==1) break;
        string b(a);
        int n=b.length();
        for(int i=0;i<n;i++) if(b[i]!=b[n-(i+1)]) b[n-(i+1)]=b[i];
        if(stoi(b)<stoi(a)){
            if(n%2==0){
                if(b[n/2-1]=='9'){
                    int idx=n/2-1;
                    while(b[idx]=='9'){
                        b[idx]='0';
                        idx--;
                    }
                    b[idx]++;
                    for(int i=0;i<n/2;i++) b[n-(i+1)]=b[i];
                }
                else{ b[n/2-1]++; b[n/2]++; }
            }
            else{
                if(b[n/2]=='9'){
                    int idx=n/2;
                    while(b[idx]=='9'){
                        b[idx]='0';
                        idx--;
                    }
                    b[idx]++;
                    for(int i=0;i<n/2;i++) b[n-(i+1)]=b[i];
                }
                else b[n/2]++;
            }
        }
        cout << abs(stoi(b)-stoi(a)) << '\n';
    }
    return 0;
}