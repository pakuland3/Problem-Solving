#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a,b;
    while((cin >> a >> b) && a!=0 && b!=0){
        int r=1;
        vector<pair<int,int>> c;
        if(a>=b) c.push_back({a,b});
        while(r!=0){
            r=a%b;
            a=b;
            b=r;
            c.push_back({a,b});
        }
        reverse(c.begin(),c.end());
        bool w=1;
        for(int i=2;i<c.size();i++){
            int k=c[i].first/c[i].second;
            if(w && k==1) w=0;
            else if(!w) w=1;
        }
        cout << (w?"A wins":"B wins") << '\n';
    }
    return 0;
}