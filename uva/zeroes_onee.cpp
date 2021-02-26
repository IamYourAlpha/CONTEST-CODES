#include<stdio.h>
#define LL long long
int n,k;
long long dp[100][100][100];

long long call(int one,int zero,int r) {
    if(one>n/2 || zero>n/2 ||zero+one>n) return 0;
    else if(dp[one][zero][r]!=-1) return dp[one][zero][r];
    else
        return dp[one][zero][r]= call(one,zero+1,(r<<1)%k) + call(one+1,zero,( (r<<1)%k+1)%k);
}

int main() {

    int tc;
    scanf("%d",&tc);
    int t_c=0;
    while(tc--) {
        scanf("%d%d",&n,&k);
        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++)
                for(int k=0; k<100; k++)
                    dp[i][j][k]=-1;
        dp[n/2][n/2][0]=1;
        if(k==0 && n%2!=0) printf("0\n");
        printf("Case %d: %lld\n",++t_c,call(1,0,1));
    }
    return 0;
}

