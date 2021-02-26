
using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define INF                         (int)1e9
#define EPS                         1e-9



// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

vector <int> graph[2000];
int dist[2000];
bool visited[2000];
int nodes,edges;

struct state {
      int node;
      state(int node) : node(node) {}
      state();
};



void bfs(int s) {
      memset(dist,-1,sizeof(dist));
    //  memset(visited,false,sizeof(visited));
      dist[0] = 0;
    //  visited[s] = true;
      queue <state> q;
      q.push(state(0));
      while(!q.empty()) {
            int now = q.front().node;
            q.pop();
            for(int i=0; i<graph[now].size(); i++) {
                  if(   dist[graph[now][i]]==-1) {
                     //   visited[ graph[now][i] ] = true;
                        dist[graph[now][i]] = 1 + dist[now];
                        q.push(state(graph[now][i]));
                  }
            }
      }
      while(!q.empty()) q.pop();
      return ;
}


int main() {
    bool ok = false;
    bool ok_ = false;
   //  freopen("input.txt","r",stdin);
      int tc;
      int u,v;
      cin >> tc;
      while(tc--) {
            if(ok_) cout << endl;
            ok_=true;
            cin >> nodes >> edges;
            for(int i=0 ; i< edges ; i++) {
                  cin >> u >> v;
                  graph[u].push_back(v);
                  graph[v].push_back(u);
            }
            bfs(0);
            for(int i=1; i<nodes; i++) cout << dist[i]<<endl;
            for(int i=0; i<2000; i++) graph[i].clear();
            ok = false;
            for(int i=0;i<2000;i++) graph[i].clear();
      }
      return 0;

}
