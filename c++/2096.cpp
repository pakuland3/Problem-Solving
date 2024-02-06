#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int maxdp[3];
int mindp[3];
int maxtmp[3];
int mintmp[3];

int main(){
    scanf("%d",&n);
    for(int i=0;i<3;i++){scanf("%d",&maxdp[i]);mindp[i]=maxdp[i];}
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            maxtmp[j]=maxdp[j];
            mintmp[j]=mindp[j];
            scanf("%d",&maxdp[j]);
            mindp[j]=maxdp[j];
        }
        maxdp[0]+=max(maxtmp[0],maxtmp[1]);
        maxdp[1]+=max(maxtmp[0],max(maxtmp[2],maxtmp[1]));
        maxdp[2]+=max(maxtmp[1],maxtmp[2]);
        mindp[0]+=min(mintmp[0],mintmp[1]);
        mindp[1]+=min(mintmp[0],min(mintmp[2],mintmp[1]));
        mindp[2]+=min(mintmp[1],mintmp[2]);
    }
    printf("%d %d",max(maxdp[0],max(maxdp[1],maxdp[2])),min(mindp[0],min(mindp[1],mindp[2])));
}