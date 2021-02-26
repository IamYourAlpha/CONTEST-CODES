using namespace std;
#include<stdio.h>
#include<queue>
#include<string.h>
#include<string>
#include<iostream>
#include<vector>

#define pii pair<int,int>


int r,c;
int Grid[1002][1002];
int time_[1002][1002];
int dx[] = {-1, +0, +0, +1};
int dy[] = {+0, -1, +1, +0};

bool valid(int x,int y) {
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}


void bfs(int x,int y) {
    int xi,yi;
    int X,Y;
    queue<pii>q;
    Grid[x][y]=1;
    q.push(make_pair(x,y));
    while(!q.empty()) {
        pair<int,int>p=q.front();
        xi=p.first;
        yi=p.second;
        q.pop();
        for(int i=0; i<4; i++) {
            X=xi+dx[i];
            Y=yi+dy[i];
            if( valid(X,Y) && Grid[X][Y]!=1 && time_[X][Y]==0 ) {
                time_[X][Y]=time_[xi][yi]+1;
                q.push( make_pair(X,Y) );
            }
        }
    }
}

int main() {
    int n,n1,r1,c1;
    while( scanf("%d %d",&r,&c)!=EOF) {
        memset(time_,0,sizeof(time_));
        memset(Grid,0,sizeof(Grid));
        if(r+c==0)  return 0;
        scanf("%d",&n);
        for(int j=0; j<n; j++) {
            scanf("%d %d",&r1,&n1);
            for(int k=0; k<n1; k++) {
                scanf("%d",&c1);
                Grid[r1][c1]=1;
            }
        }
        scanf("%d %d",&r1,&c1);
        bfs(r1,c1);
        scanf("%d %d",&r1,&c1);
        printf("%d\n",time_[r1][c1]);
    }
    return 0;
}

