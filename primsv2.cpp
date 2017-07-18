using namespace std;
#include<stdio.h>
#include<iostream>
#include<vector>
#define inf 1<<16
int a,b,u,v,n,i,j,ne=1;
int visited[100];
int mini,mincost;
int cost[100][100];

int main()
{


    printf("enter the  number of the nodes \n");
    cin>>n;
    printf("input the  graph  in the form of the matrix \n");
    for( i=1; i<=n; i++)
        for( j=1; j<=n; j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
                cost[i][j]=inf;
        }
    visited[1]=1;
    cout<<endl;
    while(ne<n)
    {
        for(i=1,mini=inf; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j]<mini)
                    if(visited[i]!=0)
                    {
                        mini=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\n edges %d: (%d %d) cost : %d",ne++,a,b,mini);
            mincost+=mini;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=inf;
    }
    printf("\n the minimum cost is %d \n",mincost);
    return 0;
}



