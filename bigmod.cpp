#include <cstdio>
#define UL unsigned long long
UL exp(UL b,UL n,UL m){
    UL x = 1;
    UL pot = b%m;
    while(n){
        if(n&(0x1)){
            x = (x*pot)%m;
        }
        pot = (pot*pot)%m;
        n>>=1;
    }
    return x;
}
int main(){
    UL b,n,m;
    while(scanf("%llu %llu %llu",&b,&n,&m)==3){
        printf("%llu\n",exp(b,n,m));
    }
    return 0;
}
