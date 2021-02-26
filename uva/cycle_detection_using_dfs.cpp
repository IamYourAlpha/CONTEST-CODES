/** this is an algo to  detect whether there is any cycle/not in a undirected graph ********************///
/**** time comp ::  O(V+E)   ************/


#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
vector < int > G[1000];
int E,N;

bool dfs(int node,int parent) {
    visited[node] = true;

    for(int i=0; i<G[node].size(); i++) {
        if(!visited[G[node][i]])
            if( dfs( G[ node ][ i ] ,node )   ) {
                return true;
            } else if(G[node][i] != node) return true;
            }
    return false;
}


bool isCyclic() {

    for(int i=1; i<=N; i++) {
        if(!visited[i])
            if(dfs(i,-1))
                return  true;
        return false;
    }
}



int main() {

    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N >> E;
        for(int ii=0; ii<E; ii++) {
        int u ,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(visited,false,sizeof(visited));
        if( isCyclic() )
            cout << "Cycle detected" << endl;
        else cout << "No Cycle detected" << endl;
    }
}
