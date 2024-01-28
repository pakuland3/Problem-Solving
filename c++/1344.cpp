#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

double calp(double p, int n){
    double result=1;
    int cnt=18-n;
    while(n--){
        result*=p;
    }
    while(cnt--){
        result*=(1-p);
    }
    return result;
}

ll cb(int n, int m){
    long long result=1;
    int cnt=m;
    while(cnt--){
        result*=n;
        n--;
    }
    cnt=m;
    while(cnt--){
        result/=m;
        m--;
    }
    return result;
}

int notP[]={0,1,4,6,8,9,10,12,14,15,16,18};
double pA,pB;
double pnotPA=0, pnotPB=0;

int main(){
    cout.precision(8);
    cin >> pA >> pB;
    pA/=100;
    pB/=100;
    for(int i=0;i<12;i++){
        pnotPA+=calp(pA,notP[i])*cb(18,notP[i]);
        pnotPB+=calp(pB,notP[i])*cb(18,notP[i]);
    }
    cout << 1-pnotPA*pnotPB;
    return 0;
}