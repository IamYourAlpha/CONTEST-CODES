#include<queue>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;

int color[1000];
vector<int>g[1000];

/*bool dfs(int u,bool flag){
     if(visited[u]>=0){
      if(visited[u]==flag)
       return true;
       else return false;
       }
      visited[u]=flag;
      if( dfs(g[u][0],flag^1) && dfs(g[u][1],flag^1) && dfs(g[u][2],flag^1) )
       return true;
       else return false;
}
*/
bool biparite() {
    queue<int>q;
    color[0]=1;
    q.push(0);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++) {
            int  v=g[u][i];
            if(color[v]==-1) {
                color[v]=1-color[u];
                q.push(v);
            } else if(color[v]==color[u]) return false;
        }
    }
    return  true;
}

int main() {
    int n;
    while( scanf("%d",&n)!=EOF ) {
        if(n==0) break;
        for(int i=0; i<n; i++)
            g[i].clear();
        int a,b;
        while(true) {
            scanf("%d%d",&a,&b);
            if( a==0 && b==0) break;

            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        //if(n&1) printf("NO\n");
        memset(color,-1,sizeof(color));
        if( biparite() ) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
