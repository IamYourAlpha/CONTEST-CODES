
#include<stdio.h>

int k;
int tc;
int memo[10000];

int gcd(int x,int y) {
      if(x==0) return y;
      else return gcd(y%x,x);
}

void pre() {
      int ans=0;
      memo[0]=0;
      for(int i=1; i<=1001; i++) {
            for(int j=1; j<=i; j++) {
                  if(gcd(i,j)>1) ans++;
            }
            memo[i]+=memo[i-1] + ans;
            ans=0;
            // printf("%d--%d\n",i,memo[i]);
      }
}


int main() {
      pre();
      scanf("%d",&tc);
      while(tc--) {
            scanf("%d",&k);
            // printf("%d\n",gcd(12,6));
            printf("%.4lf\n",(double)(memo[k]/(double)(k*k) ) );
      }
      return 0;
}
