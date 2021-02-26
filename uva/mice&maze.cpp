using namespace std;
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>



int graph [1000][1000];
int d[200];

int n,ext,mn,edge;
/*
class Compa {
public:
      bool operator()(node& x1, node& x2) {
            if (x1.wi < x2.wi) return true;
            return false;
      }
};

priority_queue<node,vector <node> ,Compa> pq;

void dijkstra(int source) {
      for(int i=1; i<=n; i++) d[i]=INT_MAX;
      d[source] = 0;

      now.s = source;
      now.wi = 0;
      pq.push(now);
      while(!pq.empty()) {
            int c = now.s;
            int weg = now.wi;
            pq.pop();
            if(weg!=d[c]) continue;
            for(int i=1; i<=edge; i++) {
                  int v = graph[i].v;
                  int np = graph[c].w + d[c];
                  if(d[v]>np) {
                        d[v] = np;
                        now.s = v;
                        now.wi=np;
                        pq.push(now);
                  }
            }
      }
}
*/

void floyd() {

      for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                  for(int j=1; j<=n; j++) {
                        graph[i][j] = min(graph[i][j],(graph[i][k] + graph[k][j]) );
                  }
            }
      }

}


int main() {
     //freopen("input.txt","r",stdin);
      int tc;
      scanf("%d",&tc);
      bool ok = false;

      while(tc--) {
            scanf("%d %d %d %d",&n,&ext,&mn,&edge);

            for(int i=1; i<=150; i++)
                  for(int j=1; j<=150; j++) {graph[i][j]=1000000000 ;}
            for(int i=0; i<edge; i++) {
                  int u,v,w;
                  scanf("%d %d %d",&u,&v,&w);
                  graph[u][v]=w;
            }
            int rat = 0;
            floyd();
            for(int i=1; i<=n; i++) {
                graph[i][i]=0;
                 //cout << i <<" " << ext << " "<<   graph[i][ext] << endl;
                  if(graph[i][ext]<=mn ) rat++;
            }
            if(ok) printf("\n"); ok = true;
            printf("%d\n",rat);
      }
      return 0;
}
