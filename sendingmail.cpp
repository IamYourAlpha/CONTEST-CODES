#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<climits>
#include<set>
using namespace std;

typedef pair<int,int>pii;
typedef vector<vector<pii> > Graph;

void dijkstra(Graph &g, int s, vector<int> &prio, vector<int> &pred) {
    int n = g.size();
    prio.assign(n, INT_MAX);
    prio[s] = 0;
    pred.assign(n, -1);
    priority_queue<pii, vector<pii> , greater<pii> > q;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d != prio[u])
            continue;
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i].first;
            int nprio = prio[u] + g[u][i].second;
            if (prio[v] > nprio) {
                prio[v] = nprio;
                pred[v] = u;
                q.push(make_pair(nprio, v));
            }
        }
    }
}
int main(){
    int tc;
    Graph g(50000+100);
    int n,m,s,t;
    int u,v,w;
    int k=0;
    scanf("%d",&tc);
    while(tc--){
       scanf("%d%d%d%d",&n,&m,&s,&t);
       for(int i=0;i<m;i++){
               scanf("%d%d%d",&u,&v,&w);
               g[u].push_back(make_pair(v,w));
                // g[v].push_back(make_pair(u,w));
       }
       vector<int>prio;
       vector<int>pred;
     dijkstra(g,s,prio,pred);

     if(prio[t]==INT_MAX) printf("Case #%d: unreachable\n", ++k);
     else printf("Case #%d: %d\n",++k,prio[t]);
     for(int i=0;i<50000+100;i++) g[i].clear();
     }

     return 0;
}


