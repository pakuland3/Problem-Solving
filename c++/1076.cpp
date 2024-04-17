#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<string, pair<ll, ll>> um;
    um["black"]={0,1};
    um["brown"]={1,10};
    um["red"]={2,100};
    um["orange"]={3,1000};
    um["yellow"]={4,10000};
    um["green"]={5,100000};
    um["blue"]={6,1000000};
    um["violet"]={7,10000000};
    um["grey"]={8,100000000};
    um["white"]={9,1000000000};
    string a,b,c;
    cin >> a >> b >> c;
    cout << (10*um[a].first+um[b].first)*um[c].second;
    return 0;
}