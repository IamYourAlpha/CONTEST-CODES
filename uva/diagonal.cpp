#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int k =0;

int main() {
    long long input;
    while(scanf("%lld",&input)==1) {
      if(input==0) return 0;
        long long ans = ceil( (3 + sqrt(9+8*input) )/2 );
        printf("Case %d: %lld\n",++k,ans);
    }
    return 0;
}
