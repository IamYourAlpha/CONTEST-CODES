#include<bits/stdc++.h>

using namespace std;


int graph[100][100];
int path[100];
int n,m;
void printPath() {
    for(int i=0; i<n; i++) printf(" %d",path[i]);
    return ;
}

bool IsSafe(int node,int posi) {
    if(graph[path[posi-1]][node]==0) return false;
    for(int i=0; i<posi; i++) if(path[i]==node) return false;
    return true;
}

bool HamiltonPath(int pos) {
    if(pos==m) {
        if(graph[path[pos-1]][0]==1) return true;
        else return false;
    }
    for(int v=1; v<m; v++) {
        if(IsSafe(v,pos)==true) {
            path[pos] = v;
            if(HamiltonPath(pos+1)==true) return true;
            path[pos] = -1;
        }
    }
    return false;
}



void solve() {
    for(int i=0; i<100; i++) path[i] = -1;
    path[0] = 0;
    if(HamiltonPath(1)==true) printPath();
    else printf("No path avaiable\n");
    return;
}

int main() {

    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v] = 1;
    }
    solve();
    return 0;
}

