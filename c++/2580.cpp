#include <bits/stdc++.h>
using namespace std;

int plate[9][9];
int h=0;
bool b=false;
bool cd=true;

void copy_arr(int (*a)[9], int (*b)[9]){
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) a[i][j]=b[i][j];
    return;
}

bool check(int x, int y, int (*arr)[9]){
    for(int i=0;i<9;i++){
        if(i!=x && arr[i][y]==arr[x][y]) return false;
        if(i!=y && arr[x][i]==arr[x][y]) return false;
    }
    int r=x/3*3;
    int c=y/3*3;
    for(int i=0;i<3;i++){
        if(arr[r][c+i]==arr[x][y]){
            if(r!=x || c+i!=y) return false;
        }
        if(arr[r+1][c+i]==arr[x][y]){
            if(r+1!=x || c+i!=y) return false;
        }
        if(arr[r+2][c+i]==arr[x][y]){
            if(r+2!=x || c+i!=y) return false;
        }
    }
    return true;
}

void sudoku(int cnt, int x, int y, int (*arr)[9]){
    if(b) return;
    if(cnt==h){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) cout << arr[i][j] << ' ';
            cout << '\n';
        }
        b=true;
        return;
    }
    int tmp[9][9]; copy_arr(tmp,arr); 
    for(int i=x;i<9;i++){
        for(int j=0;j<9;j++){
            if(i==x && j==0){j=y+1;if(j==9) continue;}
            bool p=false;
            if(tmp[i][j]!=0) continue;
            for(int k=1;k<10;k++){
                tmp[i][j]=k;
                if(check(i,j,tmp)){
                    sudoku(cnt+1,i,j,tmp);
                    if(!cd){p=false;cd=true;}
                    else p=true;
                }
                tmp[i][j]=0;
            }
            if(!p){cd=false;return;}
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<9;i++) for(int j=0;j<9;j++){cin >> plate[i][j];if(plate[i][j]==0) h++;}
    sudoku(0,0,-1,plate);
    return 0;
}