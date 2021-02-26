#include<stdio.h>

long long dp[ 210000000];

void pre_pro()
{
    dp[0]=0;
    dp[1]=0;
    for(int i=2; i<= 210000000; i++)
        dp[i]=dp[i-1]+(i-1);
}

/*long long dp(long long n){
    if(n==0) return 1;
    return n +dp(n-1);
}
*/
int main()
{
    long long n;
    pre_pro();
   while( scanf("%lld",&n)!=EOF && n>=0)
    printf("%lld\n",n*2+dp[n-1]);
    return 0;
}
