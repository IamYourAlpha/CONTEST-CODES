#include<stdio.h>
#include<string.h>
typedef long long ll;

ll make,len;
ll memo[30][10000][30];
ll arr[27]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};

ll dp(ll index,ll make_,ll take) {

      if(index==26) return 0;
      if(take==0) {
            return make_==0;
      } else if(memo[index][make_][take]!=-1) return memo[index][make_][take];
      else return memo[index][make_][take] = dp(index+1,make_-arr[index],take-1) + dp(index+1,make_,take);

}


int main() {
      int k =0;

      memset(memo,-1,sizeof(memo));
      while(scanf("%lld %lld",&len,&make)!=EOF) {
            if( !len && !make )  return 0;

            printf("Case %d: %lld\n",++k,dp(0,make,len));
      }
      return 0;
}
