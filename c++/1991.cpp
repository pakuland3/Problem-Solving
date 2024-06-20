#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<char>> graph(26,vector<char> (2));

void preoder_traversal(char cur){
    cout << cur;
    if(graph[cur-'A'][0]!='.') preoder_traversal(graph[cur-'A'][0]);
    if(graph[cur-'A'][1]!='.') preoder_traversal(graph[cur-'A'][1]);
}

void inorder_traversal(char cur){
    if(graph[cur-'A'][0]!='.') inorder_traversal(graph[cur-'A'][0]);
    cout << cur;
    if(graph[cur-'A'][1]!='.') inorder_traversal(graph[cur-'A'][1]);
}

void postorder_traversal(char cur){
    if(graph[cur-'A'][0]!='.') postorder_traversal(graph[cur-'A'][0]);
    if(graph[cur-'A'][1]!='.') postorder_traversal(graph[cur-'A'][1]);
    cout << cur;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char a,b,c;
        cin >> a >> b >> c;
        graph[a-'A'][0]=b;
        graph[a-'A'][1]=c;
    }
    preoder_traversal('A');
    cout << '\n';
    inorder_traversal('A');
    cout << '\n';
    postorder_traversal('A');
    return 0;
}