#include<iostream>
#include<stdio.h>
using namespace std;

unsigned long fun(unsigned long  n) {
      unsigned long i;
      unsigned long  long len=1<<32-1;
      unsigned long pow_=1<<32-1;
      unsigned long long sum=0;
      for(i=len; i>0; i/=2) {
            if(!(n&i)) {
                  sum+= pow_;
            }
            pow_/=2;
      }
      return sum;
}

int main() {

      int tc;
      unsigned  long demo;
      scanf("%d",&tc);
      while(tc--) {

            scanf("%lu",&demo);
            unsigned long ans=  fun(demo);
            printf("%lu\n",ans);
      }
      return 0;
}

