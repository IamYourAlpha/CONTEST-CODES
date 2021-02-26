using namespace std;
#include<bits/stdc++.h>

const int MAX = 100;

int graph[100][100],color[1000],ans[1000];
int edges,vertex;
int c=0;
int black;
int maxblack;


bool ok(int node) {
    for(int i=1; i<=vertex; i++) {
        if(graph[i][node] && color[i]==1) return false;
    }
    return true;
}


void paint(int node) {
     black = 0;
     c = 0;
    if(node>vertex) {
       black = 0;
        for(int i=1; i<=vertex; i++)
            if(color[i]==1) black++;
        if(black>maxblack) {
            maxblack = black;
            c = 0;
            for(int i=1; i<=vertex; i++) {
                if(color[i]==1)
                    ans[c++] = i;
            }
            return ;
        }
    } else {
        color[node] = 0;
        paint(node+1);
        color[node] = 1;
        if(ok(node))
            paint(node+1);
        color[node] = 0;

    }
    return ;
}


int main() {
  freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> vertex >> edges;
        memset(color,0,sizeof(color));
        memset(graph,0,sizeof(graph));
       // memset(color,0,sizeof(color));

        for(int i=0; i<edges; i++) {
            int u,v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        paint(1);
        cout << maxblack << endl;
        for(int i=0; i<maxblack; i++)
            cout << ans[i] << " ";
    }
    return 0;
}
