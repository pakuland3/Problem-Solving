#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int maxdp[3];
int mindp[3];
int tmp[3];

int main(){
    scanf("%d",&n);
    for(int i=0;i<3;i++){scanf("%d",&maxdp[i]);mindp[i]=maxdp[i];}
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++) scanf("%d",&tmp[j]);
        maxdp[0]=max(maxdp[0],maxdp[1])+tmp[0];
        maxdp[1]=max(maxdp[0],max(maxdp[2],maxdp[1]))+tmp[1];
        maxdp[2]=max(maxdp[1],maxdp[2])+tmp[2];
        mindp[0]=min(mindp[0],mindp[1])+tmp[0];
        mindp[1]=min(mindp[0],min(mindp[2],mindp[1]))+tmp[1];
        mindp[2]=min(mindp[1],mindp[2])+tmp[2];
    }
    printf("%d %d",max(maxdp[0],max(maxdp[1],maxdp[2])),min(mindp[0],min(mindp[1],mindp[2])));
}