#include <bits/stdc++.h>
#define fi first
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l[11];
    int rank=1;
    for(int i=0;i<11;i++){
        cin >> l[i];
        rank*=l[i];
    }
    int ***********g=new int**********[l[10]];
    int emt=0,cnt=0;
    queue<pair<int*,int>> Q;
    for(int i=0;i<l[10];i++){
        g[i]=new int*********[l[9]];
        for(int j=0;j<l[9];j++){
            g[i][j]=new int********[l[8]];
            for(int k=0;k<l[8];k++){
                g[i][j][k]=new int*******[l[7]];
                for(int m=0;m<l[7];m++){
                    g[i][j][k][m]=new int******[l[6]];
                    for(int n=0;n<l[6];n++){
                        g[i][j][k][m][n]=new int*****[l[5]];
                        for(int o=0;o<l[5];o++){
                            g[i][j][k][m][n][o]=new int****[l[4]];
                            for(int p=0;p<l[4];p++){
                                g[i][j][k][m][n][o][p]=new int***[l[3]];
                                for(int q=0;q<l[3];q++){
                                    g[i][j][k][m][n][o][p][q]=new int**[l[2]];
                                    for(int r=0;r<l[2];r++){
                                        g[i][j][k][m][n][o][p][q][r]=new int*[l[1]];
                                        for(int s=0;s<l[1];s++){
                                            g[i][j][k][m][n][o][p][q][r][s]=new int[l[0]];
                                            for(int t=0;t<l[0];t++){
                                                int gg;
                                                cin >> gg;
                                                g[i][j][k][m][n][o][p][q][r][s][t]=gg;
                                                if(gg==1) Q.push({new int[]{i,j,k,m,n,o,p,q,r,s,t},0}),cnt++;
                                                if(gg==-1) emt++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    auto sol=[&](int *n){ return g[n[0]][n[1]][n[2]][n[3]][n[4]][n[5]][n[6]][n[7]][n[8]][n[9]][n[10]]; };
    int res=0;
    while(Q.size()){
        int *n=Q.front().fi;
        int co=Q.front().second;
        res=max(res,co);
        Q.pop();
        for(int d:{1,-1}){
            for(int i=0;i<11;i++){
                n[i]+=d;
                int fl=0;
                for(int j=0;j<11;j++) if(l[10-j]<=n[j] || n[j]<0) fl=1;
                if(fl || sol(n)==1 || sol(n)==-1){
                    n[i]-=d;
                    continue;
                }
                int *x=new int[11];
                for(int i=0;i<11;i++) x[i]=n[i];
                Q.push({x,co+1});
                g[n[0]][n[1]][n[2]][n[3]][n[4]][n[5]][n[6]][n[7]][n[8]][n[9]][n[10]]=1;
                n[i]-=d;
                cnt++;
            }
        }
    }
    cout << (rank-emt==cnt?res:-1);
    return 0;
}