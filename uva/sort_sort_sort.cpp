#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


struct s {
      ll n;
      ll mod_val;
} a[10000+62];

bool comp(s x,s y) {
      if(x.mod_val<y.mod_val) return true;
      if(x.mod_val==y.mod_val && (  !(y.n&1) && (x.n&1)  ) )   return true;
      if(x.mod_val==y.mod_val && ( (x.n&1) && (y.n&1)  && x.n>y.n ) )   return true;
      if(x.mod_val==y.mod_val && ( !(x.n&1) && !(y.n&1)  && x.n<y.n) ) return true;
      return false;
}


int main() {
      ll N,mod;
      int p;
      while( scanf("%lld %lld",&N,&mod)!=EOF) {
            if(N==0 && mod==0){printf("0 0\n");  return 0;}
            for(int i=0; i<N; i++)
                  scanf("%lld",&a[i].n);
            for(ll i=0; i<N; i++)
                  a[i].mod_val=a[i].n%mod;
            sort(a,a+N,comp);
            printf("%lld %lld\n",N,mod);
            for(ll i=0; i<N; i++) printf("%lld\n",a[i].n);
      }


      return 0;
}




