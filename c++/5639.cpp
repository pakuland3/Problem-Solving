#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Node{
    Node *l,*r;
    int v;
};

Node *root;

void connect_node(int t){
    Node *n=(Node*)malloc(sizeof(Node));
    n->l=n->r=NULL;
    n->v=t;
    Node *now=root;
    while(1){
        if(now->v>n->v){
            if(now->l) now=now->l;
            else{
                now->l=n;
                break;
            }
        }
        else{
            if(now->r) now=now->r;
            else{
                now->r=n;
                break;
            }
        }
    }
}

void postorder(Node *node){
    if(node==NULL) return;
    postorder(node->l);
    postorder(node->r);
    cout << node->v << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    root=(Node*)malloc(sizeof(Node));
    root->v=t;
    root->l=root->r=NULL;
    while(cin >> t) connect_node(t);
    postorder(root);
    return 0;
}