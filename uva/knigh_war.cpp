#include<stdio.h>
int ans[100][100];
int mat[100][100];
bool visited[100][100];
int r,c,m,n,w;
int node_1,node_2;

int dx[] = {1, 1, 1, 1, -1, -1, -1, -1};
int dy[] = {1, 1, -1, -1, -1, -1, 1, 1};

void DFS(int node1,int node2) {
    if(visited[node1][node2]) return;
    visited[node1][node2]=true;
    for(int i=0; i<8; i++) {
        node_1= node1+ dx[i]*m;
        node_2= node2+ dy[i]*n;
        if(node_1<r && node_1>=0 && node_2>=0 && node_2<c && mat[node_1][node_2]==1) {
            ans[node_1][node_2]++;
            DFS(node_1,node_2);
        }
    }

}

int main() {
    int t_c;
    int xc,yc;
    scanf("%d",&t_c);
    while(t_c--) {
        scanf("%d %d %d %d %d",&r,&c,&m,&n,&w);
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                visited[i][j]=false;
                mat[i][j]=1;
                ans[i][j]=0;
            }
        }
        for(int i=0; i<w; i++) {
            scanf("%d%d",&xc,&yc);
            mat[xc][yc]=0;
        }
        DFS(0,0);
        int E,O;
        E=O=0;
        int i,j;
        for( i=0; i<r; i++) {
            for( j=0; j<c; j++) {
                if(ans[i][j] || (!i && !j)){
                    if( (ans[i][j]%2)==0) E++;
                    else O++;
                    printf(" %d ",mat[i][j]);

            }
        }
          printf("\n");
    }
    printf("%d %d\n",E,O);
    }
    return 0;
}

