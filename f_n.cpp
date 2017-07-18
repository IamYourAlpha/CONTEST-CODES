#include<stdio.h>
#define ll long long

int main() {
                ll n,N;
                ll even;
                scanf("%lld",&n);
                /*  ll even = (n/2)*( (n/2)+1 );
                  ll  tot= (n*(n+1))/2;
                  ll odd=-1* (tot-even);
                  */
                if(n==1) {
                                printf("-1");
                                return 0;
                }
                if(n==2) {
                                printf("1");
                                return 0;
                }
                if(n==3) {
                                printf("-2");
                                return 0;
                }
                if(n&1) {
                                ll f_e= 2;
                                ll L_e=n-1;
                                N= (f_e+L_e)/2;
                                //N=N-1;
                                even= N*(N+1);
                } else {
                                ll f_e= 2;
                                ll L_e=n;
                                N= (f_e+L_e)/2;
                                //  N=N-1;
                                even= N*(N+1);
                }
                ll odd=-1*( (n)*(n) );
                printf("%lld %lld\n",even,odd);
                printf("%lld",even+odd);
                return 0;
}
