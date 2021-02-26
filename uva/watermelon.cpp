#include<stdio.h>
#define MAX 1000000
#define ll long long

ll dp[MAX+7];
ll input;

void prep(){
    ll n;
    for(int i=0;i<=MAX;i++) dp[i]=0;
    dp[4]=1;
    for(int i=5;i<=MAX;i++){
            n=(i/2)-1;
    dp[i]=dp[i-1]+2*( (n* (n+1) )/2);
    if( !(i&1) ) dp[i]-=n;
    }
}

int main(){
    prep();
    int tc;
    scanf("%d",&tc);
    while(tc--){
            scanf("%lld",&input);
            if(input==0) return 0;
    else printf("%lld\n",dp[input]);
    }
    return 0;
}
