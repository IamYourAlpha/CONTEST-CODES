using namespace std;
#include<bits/stdc++.h>
#define MSX(a,b) (a)>(b) ? a:b
#define ll long long

ll memo[500][10000];
ll p[50000+500];
ll w[10000+100];
ll make;
ll n;
ll dp(ll index,ll amount) {
     if(index<n){ printf("hi\n"); return 0;}
     else if(memo[index][amount]!=-1) {  return  memo[index][amount];}
    else return  memo[index][amount] = (w[index]+amount<=make) ?  MSX(  p[index]+ dp(index+1,amount+w[index]),dp(index+1,amount) ) : dp(index+1,amount);
}


int main() {
     int tc;
     scanf("%d",&tc);
     while(tc--) {
          ll e,f;
          scanf("%lld %lld",&e,&f);

          scanf("%lld",&n);
          for(ll i=0; i<n; i++) {
               scanf("%lld %lld",&p[i],&w[i]);
          }
          memset(memo,-1,sizeof(memo));
          ll make= f-e;
          printf("%lld\n",make);

          //printf("%lld\n",amount);
          printf("The minimum amount of money in the piggy-bank is %lld.\n",dp(0,0));
     }
     return 0;
}
