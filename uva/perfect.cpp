/*             iiiiiiiiiiinnnnnnnnnnnnnnnnttttttttttttttttttiiiiiiiiiiiiiisssssssssssaaaaaaaaaaaarrrrrrrrrrrrrrr*/

using namespace std;
#include<bits/stdc++.h>


bool prime[10000000+2];
//vector <int> prime;
void seive() {
     memset(prime,true,sizeof(prime));
     //memset(prime,false,sizeof(prime));
     prime[0]=prime[1]=false;
     prime[2]=true;
     for(int i=4; i*i<1000000000; i+=2) prime[i]=false;
     for(int i=3; i*i<1000000000; i++) {
          if(prime[i])
               for(int j=i+i; j*j<1000000000; j+=i)
                    prime[j]=false;

     }
     //  int c=0;
     // for(int i=0;i*i<1000;i++) if(prime[i]) { printf("%d\n",i);}
}

int tot(int n) {
     int sum=0;
     while(n>0) {
          sum+=n%10;
          n/=10;
     }
     return sum;
}


int prime_sum(int n) {
     int i=2;
     int sum=0;
     int c=0;
     int k=n;
     if(n<=31622 && prime[n] ) return -2;

     while( n>1 && i<=31607 ) {
          while( prime[i]  && ( n%i==0 )  && n>1) {
               n=n/i;
               ++c;
          }
          sum = sum + (c*tot(i));
          //printf("tst::%d %d\n",tot(i));
          i++;
          c=0;
     }
     if(k==n) return -2;
     if(n>1)  sum+=tot(n);
     return sum;
}


int main() {
     int tc;
     int tot_,prime_sum_;
     scanf("%d",&tc);
       seive();
     while(tc--) {
          int n;
          scanf("%d",&n);
          for(int i=n+1;; i++) {
               // printf("%d
               if(tot(i)==prime_sum(i)) {
                    printf("%d\n",i);
                    break;
               }
               // printf("pase ::%d \n",i);
               //   printf("%d %d\n",tot(i),prime_sum(i));

          }
     }
     return 0;
}
