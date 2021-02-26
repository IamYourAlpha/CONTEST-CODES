#include<stdio.h>


int a,b,u,v,n,ne=1,i,j;
int visited[100];
int mini,mincost=0,cost[100][100];
int main()
{
    printf("\nenter the number of the edges");
    scanf("%d",&n);

    printf("\nenter the cost ");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0) cost[i][j]=999;
        }
    visited[1]=1;

    while(ne<n)
    {
        for(i=1,mini=999; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j]<mini)
                    if(visited[i]!=0)
                    {
                        mini=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
        if( visited[u]==0 || visited[v]==0)
        {
            printf("\n  edges %d : %d %d %d ",ne++,a,b,mini);
            mincost+=mini;
            visited[b]=1;
        }
        cost[a][b]= cost[b][a]=999;
    }
    printf("\n minimun cost %d ", mincost);
    return 0;
}

