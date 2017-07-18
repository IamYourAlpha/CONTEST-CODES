#include<stdio.h>
#define NN 2000
#define inf 1e9
int n,e;
int a,b;
int s[NN];
int t[NN];
float dp[NN][NN];
float r[NN];
float d[NN],mintemp;
int path[NN][NN];
void printPath(int i, int j, char p) {
    if (!path[i][j]) {
        if (!p)
            printf("%d ", i);
        printf("%d", j);
        if (j != b)
            putchar(' ');
    } else {
        printPath(i, path[i][j], p);
        printPath(path[i][j], j, 1);
    }
}


float max(float a,float b)
{
    return (a>b)?a:b;
}
float min(float a,float b)
{
    return (a<b)?a:b;
}


void floyd_()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                dp[j][k]= min(dp[j][k], max(dp[j][i],dp[i][k]));
}

void clear_floyd()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            dp[i][j]=inf;
            path[i][j]=0;
        }
}

void again_floyd()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                if(dp[j][k]>dp[j][i]+dp[i][k])
                {
                    dp[j][k]= dp[j][i]+dp[i][k];
                    path[j][k]=i;
                }
}

    int main()
    {
        while(scanf("%d%d",&n,&e)==2)
        {
            scanf("%d%d",&a,&b);
            clear_floyd();
            for(int i=0; i<e; i++)
            {
                scanf("%d%d%f%f",&s[i],&t[i],&r[i],&d[i]);
                dp[s[i]][t[i]]= min(dp[s[i]][t[i]],r[i]);
                dp[t[i]][s[i]]= min(dp[t[i]][s[i]],r[i]);
            }
            floyd_();
            mintemp= dp[a][b];
            clear_floyd();
            for(int i=0; i<e; i++)
                if(r[i]<mintemp+1e-6)
                {
                    dp[s[i]][t[i]]= min(dp[s[i]][t[i]],d[i]);
                    dp[t[i]][s[i]]= min(dp[t[i]][s[i]],d[i]);
                }
            again_floyd();
         printPath(a, b, 0);
         putchar('\n');
        printf("%.1f %.1f\n", dp[a][b], mintemp);
        }
        return 0;
    }

