#include<stdio.h>
#include<math.h>
#include<string.h>



int dp[120][120];
int N,R;
int S,D,G;

int max(int a,int b)
{
	return (a>b)?a:b;
}
int min(int a,int b)
{
	return  (a<b)?a:b;
}

void floyd(){
         for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                for(int k=1; k<=N; k++)
                    dp[j][k]= max(dp[j][k],min(dp[j][i],dp[i][k]));
}

int main() {


    int u,v,w;
    int tc=0;
    while(scanf("%d%d",&N,&R) && N|R) {
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++) dp[i][j]=-999;
        for(int i=1; i<=N; i++) dp[i][i]=0;
        for(int i=1; i<=R; i++) {
            scanf("%d%d%d",&u,&v,&w);
            dp[u][v]=w;
            dp[v][u]=w;
        }
        scanf("%d%d%d",&S,&D,&G);
       floyd();

                    printf("Scenario #%d\n",++tc);
        printf("Minimum Number of Trips = %d\n\n",(int)ceil(G*1.00/(dp[S][D]-1)));

    }
    return 0;

}
