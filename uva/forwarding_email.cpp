#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int edges;
vector <int> graph,sum;
vector<bool> visited;
int count_=0;



int dfs(int node) {
  //  if(visited[node]) return ;
     int tot = 0;
      visited[node] = true;
            if(graph[node]!=-1 && !visited[ graph[node] ] ) tot+= 1+ dfs( graph[node] );
            visited[node] = false;
            return sum[node]=tot;
}


int main() {
freopen("input.txt","r",stdin);
      int tc;
      int k =0;
      scanf("%d",&tc);
      while(tc--) {
            scanf("%d",&edges);
            graph.assign(edges,-1);
            for(int i=0; i<edges; i++) {
                  int u,v;
                  scanf("%d %d",&u,&v);
                  graph[u-1] = v-1;
            }
            sum.assign(edges,-1);
            visited.assign(edges,false);

            int nodes = -1e7;
            count_=0;
            int ans ;
            for(int i=0; i<edges; i++) {
                    count_=0;
                  if( sum[i]==-1)
                  dfs(i);
                  if(sum[i]>nodes) {
                        nodes = sum[i];
                        ans = i;
                  }
            }
                  printf("Case %d: %d\n",++k,ans+1);
                  nodes = -1e7;
                  count_=0;
      }
      return 0;
}
