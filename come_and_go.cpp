#include<bits/stdc++.h>
using namespace std;

#define LIM 2020

vector <int> grid[ LIM ];
vector <int> rgrid[ LIM ];
vector <int> sorted_node;
int visited [LIM];
int n,m;

void reset() {
    for(int i=0; i<LIM ; i++) {
        grid[i].clear();
        rgrid[i].clear();
        visited[i] = 0;
    }
    sorted_node.clear();
}


void dfs1(int node) {
    visited[node] = 1;

    for(size_t i = 0 ; i < grid[node].size() ; i++) {
        if(!visited [ grid[ node ] [ i ] ]) dfs1(grid[ node ] [ i ]);

        sorted_node.push_back(node);
    }
}

void dfs2(int node) {
    visited[node] = 1;


    for(size_t i = 0 ; i < rgrid[node].size() ; i++) {
        if(!visited [ rgrid[ node ] [ i ] ]) dfs2(rgrid[ node ] [ i ]);
    }
}


bool kosaraju() {

     dfs1(1);
     for(int i=1;i<n;i++)  if(!visited[i]) return false;

    for(int i=1; i<LIM; i++) visited[i] = 0;

    dfs2(1);
   //cout << " demo " << sorted_node[sorted_node.size()-1] << endl;
    for(int i = 1 ; i <= n ; i++) if(!visited[i]) return false;

    return true;
}



int main() {
  freopen("input.txt","r",stdin);
    while(scanf("%d %d",&n,&m)==2) {
        if(n==0 && m==0) return 0;
        reset();
        for(int i=0; i<m; i++) {
            int u,v,p;
            scanf("%d %d %d",&u,&v,&p);

            if(p==1) {
                grid[u].push_back(v);
                rgrid[v].push_back(u);
            } else {
                grid[u].push_back(v);
                grid[v].push_back(u);
                rgrid[u].push_back(v);
                rgrid[v].push_back(u);

            }
        }

        bool ans = kosaraju();
        if(ans == true) cout << "1" << endl;
        if(ans == false) cout << "0" << endl;

     }
    return 0;
}
