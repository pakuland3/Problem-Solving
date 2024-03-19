#include <bits/stdc++.h>
using namespace std;

int n,a,tmp;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while(n--){
        cin >> a;
        if(a==0 && pq.empty()) cout << "-1\n";
        else if(a==0 && !pq.empty()){cout << pq.top() << '\n'; pq.pop();}
        else for(int i=0;i<a;i++){cin >> tmp;pq.push(tmp);}
    }
    return 0;
}