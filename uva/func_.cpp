#include<stdio.h>

long gcd(long long m,long long n){
if(m==0) return n;
else return gcd(n%m,m);
}


int main(){
    long long n;
    while(scanf("%lld",&n)!=EOF){
            long long c=0;
            n=1000000000-1;
            for(int m=0;m<n;m++){
                if(gcd(m,n)==1) c++;
   // printf("%d\n",gcd(m,n));
            }
            printf("%lld\n",c);
    }
    return 0;
}


