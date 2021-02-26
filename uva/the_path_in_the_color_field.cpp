#include<bits/stdc++.h>

using namespace std;

typedef struct {
    int posx;
    int posy;
    int step;
} galaxy;


int dim;
int dx[] = {-1, +0, +0, +1};
int dy[] = {+0, -1, +1, +0};
int grid[100][100];
int visited[100][100];
queue <galaxy> q;
galaxy current,now;

bool valid(int x,int y) {
    if(x>=0 && x<dim && y>=0 && y<dim) return true;
    return false;
}

int bfs(int sx,int sy) {
//cout << "called";
    visited[sx][sy] = 1;
    current.posx = sx;
    current.posy = sy;
    q.push(current);
    while(!q.empty()) {
        current = q.front();
        q.pop();
        if(grid[current.posx][current.posy]==3)  {cout << current.step<<endl; return current.step;}
        for(int i=0; i<4; i++) {
            int x = current.posx;
            int y = current.posy;
            int X =  x + dx[i];
            int Y =  y + dy[i];
            if(valid(X,Y)) {
                now.posx = X;
                now.posy = Y;
                now.step = current.step + 1;
                q.push(now);
                //visited[X][Y] = 1;
            }
        }
    }
    return 1<<30;
}


int main() {
    freopen("input.txt","r",stdin);

    int dim;
    int ans;
    int final_ans;

    scanf("%d\n",&dim);

    memset(visited,0,sizeof(visited));

    for(int i=0; i<dim; i++)
        for(int j=0; j<dim; j++) scanf("%d",&grid[i][j]);
    final_ans = -1;

    for(int i=0; i<dim; i++) {
        ans = 1<<30;
        for(int j=0; j<dim; j++) {
            if(grid[i][j]==1) {
                //   cout <<"debug" <<  ans << endl;
                //start bfs as we get 1
                ans = min(ans,bfs(i,j));
                final_ans = max(ans,final_ans);
                memset(visited,0,sizeof(visited));
                while(!q.empty()) q.pop();

            }
        }
    }
    printf("%d\n",final_ans);

    return 0;
}
