#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int set_A[500];
int set_B[500];
int visited[500],e[500];
int graph[500][500];
int n,m;

void fresh() {
    for(int i=0; i<200; i++) visited[i] = 0;
}


int bpm(int node) {
    for(int i=0; i<m; i++) {
        if(!visited[i] && graph[node][i]) {
            visited[i]= 1;
            if( bpm( e[i] ) || e[i]==-1) {
                e[i] = node;
                return 1;
            }
        }
    }
    return 0;
}


int main() {
    int tc;
//freopen("in.txt","r",stdin);
    int k =0;

    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&set_A[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++) scanf("%d",&set_B[i]);
        memset(graph,0,sizeof(graph));
        memset(visited,0,sizeof(visited));
        memset(e,-1,sizeof(e));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(set_A[i]==0) {
                    if(set_B[j]!=0) continue ;
                    else graph[i][j] = 1;
                } else if(set_B[j]%set_A[i]==0) graph[i][j] = 1;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            memset(visited,0,sizeof(visited));
            if(bpm(i)) ans++;
        }
        printf("Case %d: %d\n",++k,ans);
    }
    return 0;
}



