#include<stdio.h>
#include<limits.h>

#define MAX(a,b)  int(a) > int(b) ? int(a) : int(b)
#define MIN(a,b)  int(a) < int(b) ? int(a) : int(b)

int edges;
int nodes;
int u,v;
int w;
int graph[100+100][100+100];
int visited[1000];
int fact(int nodes) {
      if(nodes==0) return 1;
      else return nodes * fact(nodes-1);
}

void reset() {
      for(int i=1; i<=100; i++)
            for(int j=1; j<=100; j++) {
                  graph[i][j] = 1e8;
                  visited[i]=0;
            }
}


void floyd() {
      for(int k=1; k<=100; k++) {
            for(int i=1; i<=100; i++) {
                  for(int j=1; j<=100; j++) {
                        graph[i][j] = MIN(graph[i][j],graph[i][k]+graph[k][j]);
                  }
            }
      }
}


int main() {
      int k =0;
    freopen("input.txt","r",stdin);
      reset();
      edges=0;
      nodes = 0;
      while(scanf("%d %d",&u,&v)!=EOF) {
            if(u==0 && v==0) return 0;
            graph[u][v] = 1;
            edges++;
            if(!visited[u]) nodes++;
            if(!visited[v]) nodes++;
            visited[u]=1;
            visited[v]=1;
            while(scanf("%d %d",&u,&v)!=EOF) {
                  if(u==0 && v==0) break;
                  graph[u][v]= 1;
                  edges++;
                  if(visited[u]==0) nodes++;
                  if(!visited[v]==0) nodes++;
                  visited[u]=1;
                  visited[v]=1;
            }
            //  printf("edges : %d ___ nodes : %d \n",edges,nodes);
            floyd();

            int ans = 0;
            int yo = 0;
            for(int i=1; i<=100; i++) {
                  for(int j=1; j<=100; j++) {
                        if(i!=j) {
                              if(graph[i][j]!=1e8) {
                                    ans  = ans + graph[i][j];
                                    yo++;
                              }
                        }
                  }
            }
//           int div = fact(nodes)/2;
                  // printf("%d\n",div);
                  printf("Case %d: average length between pages = %.3lf clicks\n",++k,(double)ans/yo);
                  edges =0;
                  nodes = 0;
                  reset();
            }
            return 0;
      }

