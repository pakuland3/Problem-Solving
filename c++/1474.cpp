#include <bits/stdc++.h>
using namespace std;

int n,m,l=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<string> arr(n);
    for(int i=0;i<n;i++){cin >> arr[i];l+=arr[i].length();}
    int left=m-l;
    if(left%(n-1)==0) for(string s:arr){
        cout << s;
        for(int i=0;i<left/(n-1);i++) cout << '_';
    }
    else{
        
    }
    return 0;
}