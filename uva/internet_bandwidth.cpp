using namespace std;

#include<bits/stdc++.h>

int n;
typedef pair <int,int> ii;
typedef vector <int>  vi;
typedef vector < vi > vii;
int res[1000][1000];
vii graph;
int s,d,e;
int flow;
int maxflow;
vi p;
int ans;
void augment(int node,int min_eg) {
    if(node==s) {
        if(node==s)
            flow = min_eg;
        return;
    } else if(p[node]!=-1) {
        augment(p[node],min(min_eg,res[p[node]][node]));
        res[p[node]][node]-=flow;
        res[node][p[node]]+=flow;
    }
}
void EdmondKarps() {
    maxflow = 0;
    while(true) {
        flow = 0;
        bitset <200> visited;
        visited.set(s);
        queue <int> q;
        q.push(s);
        p.assign(200,-1);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node==d) break;
            for(int i=0; i<graph[node].size(); i++) {
                if(!visited.test( graph[node][i] ) && res[node][graph[node][i]]>0) {
                    p[graph[node][i]] = node;
                    visited.set(node);
                    q.push(graph[node][i]);
                }
            }
        }
        augment(d,INT_MAX);
        if(flow==0) break;
        else  maxflow = maxflow + flow;
    }
}



int main() {
   // freopen("in.txt","r",stdin);
    int k =0;
    while(scanf("%d",&n)==1) {
      if(n==0) return 0;
        scanf("%d %d %d",&s,&d,&e);
        s--;
        d--;
        graph.assign(n,vi());
        memset(res,0,sizeof(res));
        for(int i=0; i<e; i++) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            u--;
            v--;
            res[u][v]+=w;
            res[v][u]+=w;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        EdmondKarps();
        printf("Network %d\nThe bandwidth is %d.\n\n", ++k, maxflow);
    }
}

