#include<vector>
#include<queue>
#include<algorithm>
# include <iostream>
#include<stdio.h>
using namespace std;
int c[4];
int col[500];
int ans;
int V,E;
vector< vector<int> >path;

bool  is_pirate(int n)
{
    //for(int i=0;i<V;i++) col[i]=1e9;
    //int src=0;
    col[n]=1;
    queue<int>q;
    q.push(n);
    c[n]++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        // vector<int>::iterator j;
        for(int j=0; j<(int)path[u].size(); j++)
        {
            int v=path[u][j];
            if(col[v]==-1)
            {
                col[v]=1-col[u];
                //cout<<col[v]<<endl;
                c[col[v]]++;
                //  cout<<c[col[v]]<<endl;
                //cout<<c[col[v]]<<endl;
                q.push(v);
            }
            else if(col[v]==col[u])
                return false;
        }
    }
    return true;
}

int main()
{
    int tc;
    int u,v;
    scanf("%d",&tc);
    while(tc--)
    {
        ans=0;
        scanf("%d %d",&V,&E);
        path.assign(V, vector<int>());
        for(int i=0; i<E; i++)
        {
            scanf("%d %d",&u,&v);
            path[u].push_back(v);
            path[v].push_back(u);
        }
        for(int i=0; i<=499; i++) col[i]=-1;
        for(int s=0; s<V; s++)
        {
            if(is_pirate(s))
            {
                //cout<<"called"<<endl;
                // cout<<c[0]<<" "<<c[1]<<endl;
                ans+= (c[0]>0 && c[1]>0)?
                      min(c[0],c[1]) : max(c[0],c[1]);
            }
            else
            {
                //cout<<"rest"<<endl;
                ans=-1;
                break;
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=10000;i++) path[i].clear();
        c[0]=0;
        c[1]=0;
        ans=0;
    }
    return 0;
}
