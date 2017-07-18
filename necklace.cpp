#include<bits/stdc++.h>
using namespace std;

int graph[1000][1000];
int n;
bool visited[1000];
int w[1000];


void dfs(int node) {
    visited[node] = true;
    for(int i=0; i<=51; i++) {
        if(!visited[node] && graph[node][i]==1)
            dfs(i);
    }
}


int euler() {
int i;
    bool flag = true;
    for(int i=0; i<=51; i++)
        if(w[i]&1 && w[i]>0) flag = false;
    if(flag==false) return 0;
    //cout << "system pause" << endl;
    if(flag) {
        for( i=0; i<=51; i++) {
            if(w[i]) {
                dfs(i);
                    for(int j=0; j<=51; j++) {
                        if(!visited[j] && w[j]>0){
                            flag =  false;
                            }
                             if(flag) return i;
                    }
                }
            }
       }
       return 0;
}


void  print(int node) {
    for(int i=0; i<=51; i++) {
        if(graph[node][i]) {
            graph[node][i]=0;
            graph[i][node]=0;
            print(i);
            printf("%d %d\n",i,node);
        }
    }
}


int main() {
  freopen("input.txt","r",stdin);
    int tc;
    int ok = false;
    int k=0;
    scanf("%d",&tc);
    while(tc--) {
      if(ok) cout << endl;
        for(int i=0;i<100;i++)
          for(int j=0;j<100;j++){ w[i]=0; graph[i][j] = 0; graph[j][i]=0; visited[i]=false;}

        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            int u;
            int v;
            scanf("%d %d",&u,&v);
            graph[u][v] = 1;
            graph[v][u] = 1;
            w[u]++;
            w[v]++;
        }
        ok = true;
        if(euler()==0)
            printf("Case #%d\nsome beads may be lost\n",++k);
        else {
            printf("Case #%d\n",++k);
            print(euler());
            }
        //    printf("debug\n");
          //   for(int i=0;i<=10;i++) cout << w[i] << endl;

    }
    return 0;
}
