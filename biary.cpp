
#include<bits/stdc++.h>
using namespace std;
const int MAX=1<<15;
int d[MAX],lmax[MAX],rmax[MAX],dmax,ans;
int dfs(int n,int u,int dis)
{
    int l=u<<1,r=u<<1|1;
    cout << r << endl;
    if(u>1<<n)
    {
        lmax[u]=dis;
        rmax[u]=dis;
    }
    else
    {
        lmax[u]=dfs(n,l,dis+d[l]);
        rmax[u]=dfs(n,r,dis+d[r]);
    }
    return max(lmax[u],rmax[u]);
}
void dfs2(int n,int u,int add)
{
    int l=u<<1,r=u<<1|1;
    if(u>1<<n)
    {
        ans+=dmax-(lmax[u]+add);
        return;
    }
    ans+=dmax-(lmax[u]+add);dfs2(n,l,add+dmax-(lmax[u]+add));
    ans+=dmax-(rmax[u]+add);dfs2(n,r,add+dmax-(rmax[u]+add));
}
int main()
{   freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=2;i<1<<(n+1);i++)
           scanf("%d",&d[i]);
        memset(lmax,0,sizeof(lmax));
        memset(rmax,0,sizeof(rmax));
        dmax=dfs(n,1,0);ans=0;dfs2(n,1,0);
         cout << dmax << endl;
        printf("%d\n",ans);
    }
    return 0;
}
