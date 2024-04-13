#include <bits/stdc++.h>
using namespace std;

string a,b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    bool f=a.length()>b.length()?1:0;
    int len_a=a.length(),len_b=b.length(),rn=0;
    if(f){
        for(int i=0;i<len_b;i++){
            int digit=a[len_a-(i+1)]+b[len_b-(i+1)]-2*'0'+rn;
            if(digit>9){a[len_a-(i+1)]=digit-10+'0';digit/=10;}
            else{a[len_a-(i+1)]=digit+'0'; digit=0;}
            rn=digit;
        }
        for(int i=len_b;i<len_a;i++){
            int digit=a[len_a-(i+1)]-'0'+rn;
            if(digit>9){a[len_a-(i+1)]=digit-10+'0';digit/=10;}
            else{a[len_a-(i+1)]=digit+'0'; rn=0; break;}
        }
        rn>0?cout << rn << a:cout << a;
    }
    else{
        for(int i=0;i<len_a;i++){
            int digit=a[len_a-(i+1)]+b[len_b-(i+1)]-2*'0'+rn;
            if(digit>9){b[len_b-(i+1)]=digit-10+'0';digit/=10;}
            else{b[len_b-(i+1)]=digit+'0'; digit=0;}
            rn=digit;
        }
        for(int i=len_a;i<len_b;i++){
            int digit=b[len_b-(i+1)]-'0'+rn;
            if(digit>9){b[len_b-(i+1)]=digit-10+'0';digit/=10;}
            else{b[len_b-(i+1)]=digit+'0'; rn=0; break;}
        }
        rn>0?cout << rn << b:cout << b;
    }
    return 0;
}