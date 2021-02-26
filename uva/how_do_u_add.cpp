#include<stdio.h>
#include<string.h>
typedef long long ll;

ll make;
ll len;
ll memo[200][200];

ll dp(ll index,ll sum) {
      if(index<len || sum<make) return 0;

      else if(memo[index][sum]!=-1) return memo[index][sum];

      else {
            ll ans_ = 0;
            ll i;
            for( i=0; i<=sum; i++) {
                  ans_ +=   (dp(sum-i,index-1)%1000000);
                  memo[index][sum] = ans_%1000000;

            }
      }
}




int main() {

      while(scanf("%lld %lld",&make,&len)!=EOF) {
            memset(memo,-1,sizeof(memo));
            memo[0][0]=1;
            if(make==0 && len==0) return 0;
            printf("%lld\n",dp(len,make));
      }
      return 0;
}
