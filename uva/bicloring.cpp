using namespace std;
#include<stdio.h>
#include<vector>
#include<queue>
#include<iostream>
int nodes;
int edges;
int color_of_node[1000];
bool path[200+5][200+5];

bool check_biparite()
{
    for(int i=0; i<=nodes; i++)
        color_of_node[i]=-1;
    color_of_node[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        //cout<<u<<endl;
        q.pop();
        for(int  v= 0; v<edges; v++)
        {
            if(color_of_node[v]==-1 && path[u][v] && path[v][u])
            {
                // printf("%d\n",vii[u][v]);
                color_of_node[v]=1-color_of_node[u];
                // cout<<"color of:"<<vii[u][v]<<" is: "<<color_of_node[vii[u][v]]<<endl;
                q.push(v);
            }
            else if(color_of_node[u]==color_of_node[v] && path[u][v] && path[v][u])
                return false;
        }
    }
    return true;
}


int main()
{
    int u,v;
    while(scanf("%d%d",&nodes,&edges)!=EOF)
    {
        if(nodes==0) return 0;
        for(int i=0; i<=200; i++)
            for(int j=0; j<=200; j++) path[i][j]=false, path[j][i]=false;
        for(int i=0; i<edges; i++)
        {
            scanf("%d%d",&u,&v);
            path[u][v]=true;
            path[v][u]=true;
        }
        if(check_biparite()==true) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
