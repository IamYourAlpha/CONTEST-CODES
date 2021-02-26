#include<stdio.h>
#include<string.h>


int A[5];
int seen[5];
//int memo[5][300];
int ret;

void dp(int taken,int sum) {
    if(taken==5 && sum==23) {
        //  printf("taken: %d   sum:: %d\n",taken,sum)
        ret=1;
        return;
    } else {

        //if(memo[taken][sum]!=-1) return memo[taken][sum];
        for(int i=0; i<5; i++) {

            if(!seen[i]) {
                seen[i]=1;
                dp(taken+1,A[i]+sum);
                dp(taken+1,A[i]-sum);
                dp(taken+1,A[i]*sum);
                seen[i]=0;
            }
        }
    }
}


int main() {

    while(true) {
        int tot=0;

        for(int i=0; i<5; i++) {
            scanf("%d",&A[i]);
            tot+=A[i];
        }
        if(tot==0 ) return 0;
        memset(seen,0,sizeof(seen));
        // memset(memo,-1,sizeof(memo));
        ret=0;

        for(int i=0; i<5; i++) {
            seen[i]=1;
            dp(1,A[i]);
            seen[i]=0;
        }
        if(ret) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
