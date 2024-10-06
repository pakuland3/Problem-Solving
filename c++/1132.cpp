#include <bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<ll,bool>> a(26,{0,1});
    ll res=0;
    ll coeffi=9;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(i==s.length()-1) a[s[s.length()-(i+1)]-'A'].S=0;
            a[s[s.length()-(i+1)]-'A'].F+=pow(10,i);
        }
    }
    priority_queue<pair<ll,bool>,vector<pair<ll,bool>>,greater<pair<ll,bool>>> asc;
    priority_queue<pair<ll,bool>> dsc;
    for(int i=0;i<26;i++){
        if(a[i].F>0){
            asc.push(a[i]);
            dsc.push(a[i]);
        }
    }
    if(asc.size()==10){
        coeffi=1;
        queue<ll> q;
        while(asc.top().S!=1){
            q.push(asc.top().F);
            asc.pop();
        }
        asc.pop();
        while(!q.empty()){
            res+=q.front()*coeffi;
            coeffi++;
            q.pop();
        }
        while(!asc.empty()){
            res+=asc.top().F*coeffi;
            coeffi++;
            asc.pop();
        }
        cout << res;
        return 0;
    }
    while(!dsc.empty()){
        res+=dsc.top().first*coeffi;
        dsc.pop();
        coeffi--;
    }
    cout << res;
    return 0;
}