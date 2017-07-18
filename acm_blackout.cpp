#include<stdio.h>
#include<iostream>
#define MAX 2147483647
using namespace std;

int N,M;
int g[1000][1000];

void floyd_warshall() {

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(g[i][j]<g[i][k]+g[k][j])
                    g[i][j]=(g[i][k]+g[k][j]);
            }
        }
    }
}

int main() {
    int tc;
    int ans1;
    int ans2;
    scanf("%d",&tc);
    while(tc--) {
        int u,v,w;
        scanf("%d %d",&N,&M);
        for(int i=0; i<1000; i++)
            for(int j=0; j<1000; j++) g[i][j]=MAX;
        for(int i=0; i<M; i++) {
            scanf("%d %d %d",&u,&v,&w);
            g[u][v]=w;
            g[v][u]=w;
        }
                floyd_warshall();
// g[ min_one_index_i][ min_one_index_j]=MAX;
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
        printf("%d\n",g[i][j]);
    }
    return 0;
}
