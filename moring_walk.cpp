#include<stdio.h>

int n,m;
int graph[10000+10][10000+10];
int visited[10000+100];
int w[10000+100];

void dfs(int node) {
    if(visited[node]) return ;
    if(!visited[node])  visited[node] = 1;
    for(int i=0; i<n; i++) {
        if(!visited[i] && graph[node][i]==1) dfs(i);
    }
    return ;
}

bool euler() {
    for(int i=0; i<10010; i++) visited[i] = 0;
    for(int i=0; i<10010; i++)
        if(w[i]>0 && w[i]&1) return false;
    for(int i=0; i<10010; i++) {
        if(w[i]>0) {
            dfs(i);
            for(int j=0; j<10010; j++) {
                if(!visited[j] && w[j]>0) return false;
            }
        }
    }
    return true;
}

int main() {

    while(scanf("%d %d",&n,&m)!=EOF) {
     for(int i=0;i<10010;i++) w[i] = 0;
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u][v] = 1;
            graph[v][u] = 1;
            w[u]++;
            w[v]++;
        }
        if(m==0) printf("Not Possible\n");
        else if(euler()) printf("Possible\n");
        else printf("Not Possible\n");
    }
    return 0;
}
