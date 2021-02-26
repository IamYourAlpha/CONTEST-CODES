#include<iostream>
#include<stdio.h>
using namespace std;

#define ll  long long

ll bin(ll n) {
      ll i;
      ll ans=0;
      for (i = 1 <<16; i > 0; i = i / 2)
            if(n&i) ans++;
      // if(n&i) printf("1"); else printf("0");
      return ans;
}

int main() {
      int tc;
      ll  n,m;
      scanf("%d",&tc);
      while(tc--) {
            scanf("%lld",&n);
            printf("%lld ",bin(n));
            ll demo;
            ll ans2=0;
            while(n) {
                  demo=n%10;
                  ans2+=bin(demo);
                  n/=10;
            }
            printf("%lld\n",ans2);
      }
}
