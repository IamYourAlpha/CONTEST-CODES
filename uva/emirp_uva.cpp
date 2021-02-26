#include<bits/stdc++.h>
#define MAX 10000000
#define ll long long

bool prime[100000000];

void seive() {
      memset(prime,true,sizeof(prime));
      prime[0]=false;
      prime[1]=false;
      prime[2]=true;

      for(int i=4; i<MAX; i+=2) prime[i]=false;
      for(int i=3; i*i<MAX; i++) {
            if(prime[i]) {
                  for(int k=i+i; k<MAX; k+=i) prime[k]=false;
            }
      }
//                for(int i=0; i<20; i++) if(prime[i]) printf("%d\n",i);
}

ll get_base(ll n) {

      // printf("%lld",n);
      ll base = 1;
      while(n>0) {
            base*=10;
            n/=10;
      }
      return base;
}
ll rev(ll n) {
      // printf("%lld\n",n);
      ll base = get_base(n);
      ll sum =0;

      while(n>0) {
            base/=10;
            sum = sum + ( (n%10)*base);

            n=n/10;
      }
      return  sum ;
}


int main() {
      seive();

      /* 1. "N is not prime.", if N is not a Prime number.
      2. "N is prime.", if N is Prime and N is not Emirp.
      3. "N is emirp.", if N is Emirp.
      */
      ll  n;
      while( scanf("%lld",&n)!=EOF) {
            if(n==2 || n==3 || n==5 || n==7) {
                  printf("%lld is prime.\n",n);
                  continue;
            };
            if(!prime[n]) printf("%lld is not prime.\n",n);
            else if(prime[rev(n)] && rev(n)!=n) {
                  printf("%lld is emirp.\n",n);

            } else printf("%lld is prime.\n",n);
      }

      return 0;
}
