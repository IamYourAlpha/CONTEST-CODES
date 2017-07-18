#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int arr[1000];
int memo[250][100][100];
int make,take,query,n;

int mod(int nn,int mm)
{
    if(nn<0)
        nn+=(ceil(-nn*1.00/mm)*mm);
    return nn%mm;
}


int dp(int n,int r,int v) {
    if(!n&&r) return 0;
     else  if(memo[n][r][v]!=-1) return  memo[n][r][v];
     else  if(r==0)  return memo[n][r][v]=(v==0);
     else return   memo[n][r][mod(v,make)] = dp(n-1,r-1,mod(v-mod(arr[n-1],make),make) ) +  dp(n-1,r,v);
     // printf("%d %d\n",ret,ret1);
}


int main() {
      //freopen("input.txt","r",stdin);
      int set_=0;
      while(scanf("%d %d",&n,&query)!=EOF) {
            int q=0;
            if(n==0 && query==0) return 0;
       printf("SET %d:\n",++set_);
            for(int i=0; i<n; i++) scanf("%d",&arr[i]);
            for(int i=0; i<query; i++) {
                  scanf("%d %d",&make,&take);
                  for(int ii=0;ii<250;ii++)
                    for(int jj=0;jj<100;jj++)
                    for(int kk=0;kk<100;kk++) memo[ii][jj][kk]=-1;
                printf("QUERY %d: %d\n",++q,dp(n,take,make));
            }
      }
      return 0;
}
