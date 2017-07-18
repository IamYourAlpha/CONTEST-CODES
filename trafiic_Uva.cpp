#include<stdio.h>
#include<math.h>
#define abs(a,b) (a-b) < 0 ? (a-b)*-1 : (a-b)
#define  INF 1e8+7

struct SS {
      int u;
      int v;
      int w;
} node[5000];

int arr[5000];
int d[5000];
int nodes,street;

void bellman() {
      d[1]=0;
      for(int i=1; i<=nodes; i++) {
            for(int j=1; j<=street; j++) {
                  if(d[ node[j].v ] > (d[ node[j].u ]+node[j].w)  && d[node[j].u]!=INF) {
                        d[ node[j].v ] = d[ node[j].u ]+node[j].w;
                  }
            }
      }
      for(int j=1;j<=nodes;j++) {if(d[ node[j].v ] > (d[ node[j].u ]+node[j].w)) d[ node[j].v ]=-INF;}

}


int main() {
      int k =0;
       freopen("input.txt","r",stdin);
      while(scanf("%d",&nodes)==1) {
            for(int i=1; i<=nodes; i++) {
                  scanf("%d",&arr[i]);
            }
            for(int i=0; i<5000; i++) d[i]=INF;
            scanf("%d",&street);
            for(int i=1; i<=street; i++) {
                  scanf("%d %d",&node[i].u,&node[i].v);
                  int ok = (arr[ node[i].v ] - arr[ node[i].u ]) * (arr[ node[i].v ] - arr[ node[i].u ]) * (arr[ node[i].v ] - arr[ node[i].u ]);
                node[i].w= ok;
            //    printf("%d\n",ok);  //  graph[v][u] = arr[ node[i].u ] - arr[ node[i].v ] ;
             //     printf("%d\n",node[i].w);
            }
            bellman();
            int q;
            scanf("%d",&q);
            printf("Set #%d\n",++k);
            for(int i=1; i<=q; i++) {
                  int demo;
                  scanf("%d",&demo);
                  if(d[demo]>=3 && d[demo]!=INF)
                    printf("%d\n",d[demo]);
                 else   printf("?\n");
                   // for(int i=0;i<5000;i++){ node[i].w=0; node[i].u=0; node[i].v=0;}
            }

      }
      return 0;
}
