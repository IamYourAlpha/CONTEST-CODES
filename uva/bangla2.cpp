#include<stdio.h>
int k;
int tc;
int memo[1000];

int gcd(int x,int y){
    if(x==0) return y;
    else return gcd(y%x,x);
}



int main(){

    scanf("%d",&tc);
    while(tc--){
        int ans=0;
            scanf("%d",&k);
            for(int i=1;i<=k;i++){
                for(int j=1;j<=k;j++){
                    if(gcd(i,j)>1) ans++;
                }
     printf("%d--%d\n",i,ans);
     ans=0;
            }

   // printf("%d\n",gcd(12,6));
    printf("%.4lf\n",(double)ans/(double)(k*k) ) ;
    }
    return 0;
}
