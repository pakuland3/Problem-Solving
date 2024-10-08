// #include <bits/stdc++.h>
// #define FI first
// #define SE second
// #define SIZE 200001
// typedef long long ll;
// using namespace std;

// int tree[SIZE*4];

// void update(int X, int node, int S, int E){
//     if(E<X || X<S) return;
//     if(S==E){
//         tree[node]++;
//         return;
//     }
//     int MID=(S+E)/2;
//     update(X,2*node,S,MID);
//     update(X,2*node+1,MID+1,E);
//     tree[node]=tree[2*node]+tree[2*node+1];
// }

// int query(int R, int node, int S, int E){
//     if(E<R) return 0;
//     if(R<=S) return tree[node];
//     int MID=(S+E)/2;
//     return query(R,2*node,S,MID)+query(R,2*node+1,MID+1,E);
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     bool FREAKINGEASYPROBLEM=0;
//     int n;
//     cin >> n;
//     bool sign=1;
//     unordered_set<ll> us;
//     vector<bool> order(n,0);
//     vector<pair<ll,int>> p;
//     // CASES
//     // if int is 0 -> do not update and change sign
//     // if int is 1 -> do not change sign and update
//     // if int is 2 -> change sign and update
//     // if int is 3 -> freakingeasyproblem
//     // if int is 4 -> ignore
//     vector<ll> q,r;
//     for(int i=0;i<n;i++){
//         int s;
//         ll a,b;
//         cin >> s >> a;
//         if(s==1){
//             bool isMinus=((a>0 && b>0) || (a<0 && b<0));
//             order[i]=0;
//             cin >> b;
//             if(a==0){
//                 if(b==0) p.push_back({0,3});
//                 if(b<0) p.push_back({0,0});
//                 if(b>0) p.push_back({0,4});
//                 continue;
//             }
//             if(a<0){
//                 if(b==0){
//                     if(us.find(0)==us.end()) us.insert(0);
//                     p.push_back({0,2});
//                     r.push_back(0);
//                     continue;
//                 }
//                 if(b%a==0){
//                     if(us.find(-b/a)==us.end()) us.insert(-b/a);
//                     p.push_back({-b/a,2});
//                     r.push_back(-b/a);
//                     continue;
//                 }
//                 p.push_back({-b/a-isMinus,2});
//                 r.push_back(-b/a-isMinus);
//                 continue;
//             }
//             if(b%a==0){
//                 if(us.find(-b/a)==us.end()) us.insert(-b/a);
//                 p.push_back({-b/a,1});
//                 r.push_back(-b/a);
//                 continue;
//             }
//             p.push_back({-b/a-isMinus,1});
//             r.push_back(-b/a-isMinus);
//         }
//         else{
//             order[i]=1;
//             q.push_back(a);
//         }
//     }
//     sort(r.begin(),r.end());
//     auto last=unique(r.begin(),r.end());
//     int pi=0,qi=0;
//     for(int i=0;i<n;i++){
//         if(order[i]){
//             if(FREAKINGEASYPROBLEM){
//                 cout << "0\n";
//                 continue;
//             }
//             int t=lower_bound(r.begin(),last,q[qi])-r.begin()+1;
//             int tt=query(t,1,1,SIZE);
//             if(us.find(q[qi])!=us.end()) cout << "0\n";
//             else cout << ((tt%2==0)^sign?'-':'+') << '\n';
//             qi++;
//             continue;
//         }
//         if(p.empty()) continue;
//         if(p[pi].SE==4){
//             pi++;
//             continue;
//         }
//         if(p[pi].SE==3) FREAKINGEASYPROBLEM=1;
//         if(p[pi].SE==0) sign=!sign;
//         else{
//             int t=lower_bound(r.begin(),last,p[pi].FI)-r.begin()+1;
//             update(t,1,1,SIZE);
//         }
//         if(p[pi].SE==2) sign=!sign;
//         pi++;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define FI first
#define SE second
#define SIZE 200001
typedef long long ll;
using namespace std;

int tree[SIZE*4];

void update(int X, int node, int S, int E){
    if(E<X || X<S) return;
    if(S==E){
        tree[node]++;
        return;
    }
    int MID=(S+E)/2;
    update(X,2*node,S,MID);
    update(X,2*node+1,MID+1,E);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int R, int node, int S, int E){
    if(E<R) return 0;
    if(R<=S) return tree[node];
    int MID=(S+E)/2;
    return query(R,2*node,S,MID)+query(R,2*node+1,MID+1,E);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    bool GAMEOVER=0;
    bool sign=1;
    int n;
    cin >> n;
    vector<bool> order(n,0);
    vector<ll> coordinates,q;
    // 0 change sign
    // 1 update
    // 2 change sign, update
    // 3 turn on GAMEOVER
    // 4 do nothing
    // 5 insert point to set and update
    // 6 5 + change sign
    vector<pair<ll,int>> updates;
    unordered_set<ll> s;
    for(int i=0;i<n;i++){
        int j;
        ll a,b;
        cin >> j >> a;
        if(j==1){
            order[i]=1;
            cin >> b;
            if(a==0){
                if(b<0) updates.push_back({0,0});
                else{
                    if(b==0) updates.push_back({0,3});
                    updates.push_back({0,4});
                }
                continue;
            }
            if(b%a==0){
                updates.push_back({-b/a,5+(a<0)});
                coordinates.push_back(-b/a);
                continue;
            }
            bool isMinus=((a>0 && b>0) || (a<0 && b<0));
            updates.push_back({-b/a-isMinus,1+(a<0)});
            coordinates.push_back(-b/a-isMinus);
        }
        else q.push_back(a);
    }
    sort(coordinates.begin(),coordinates.end());
    auto last=unique(coordinates.begin(),coordinates.end());
    int ui=0,qi=0;
    for(int i=0;i<n;i++){
        if(order[i]){
            if(updates[ui].SE==3) GAMEOVER=1;
            if(updates[ui].SE==0 || updates[ui].SE==2 || updates[ui].SE==6) sign=!sign;
            if(updates[ui].SE==4 || updates[ui].SE==3 || updates[ui].SE==0){
                ui++;
                continue;
            }
            if(updates[ui].SE==5 || updates[ui].SE==6 && s.find(updates[ui].FI)==s.end()) s.insert(updates[ui].FI);
            int t=lower_bound(coordinates.begin(),last,updates[ui].FI)-coordinates.begin()+1;
            update(t,1,1,SIZE);
            ui++;
            continue;
        }
        if(GAMEOVER) cout << "0\n";
        else{
            if(s.find(q[qi])!=s.end()) cout << "0\n";
            else{
                int tt=lower_bound(coordinates.begin(),last,q[qi])-coordinates.begin()+1;
                int t=query(tt,1,1,SIZE);
                cout << ((t%2==0)^sign?'-':'+') << '\n';
            }
            qi++;
        }
    }
    return 0;
}