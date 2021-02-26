#include<bits/stdc++.h>
using namespace std;


struct node {
    int x, y, d, tm;
    node(int a,int b,int c,int tim) {
        x = a;
        y  = b;
        d =  c;
        tm = tim;
    }
};

int row;
int pos;
int col;
int visited[1000][1000][10];
int grid[1000][1000];
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
int sx,sy,dex,dey;

bool valid(int x,int y) {
    if(x<0 || x>=row || y<0 || y>=col) return false;
    if(grid[x][y]) return false;
    if(grid[x-1][y]) return false;
    if(grid[x][y-1]) return false;
    if(grid[x-1][y-1]) return false;
    return true;
}


int bfs() {
    queue < node > q;
    //cout <<  "enter " << endl;
    if(valid(sx,sy)){
    q.push(node(sx,sy,pos,0) );
    visited[sx][sy][pos] = true;
    }
    while(!q.empty()) {

        node demo = q.front();
         q.pop();
        cout << demo.x << " " << demo.y << endl;
        if(demo.x==dex && demo.y==dey) {
            //      cout << "done" << endl;
            return demo.tm;
        }


            if(!visited[demo.x][demo.y][ (demo.d+1)%4 ]) {
                visited[demo.x][demo.y][ (demo.d+1)%4 ] = true;
                q.push(node(demo.x,demo.y,(demo.d+1)%4,demo.tm+1));
            }
        if(!visited[demo.x][demo.y][ (demo.d+3)%4 ]) {
            visited[demo.x][demo.y][ (demo.d+3)%4 ] = true;
            q.push(node(demo.x,demo.y,(demo.d+3%4),demo.tm+1));
        }
        for(int i=1; i<=3; i++) {
            int X = demo.x+ dx[demo.d]*i;
            int Y = demo.y+ dy[demo.d]*i;
            int Z = demo.d;
            if( valid(X,Y) ) {
                if( !visited[X][Y][Z] ) {
                    visited[X][Y][Z] = true;
                    q.push(node(X,Y,Z,demo.tm+1));
                }
            } else break;
        }
    }
    return -1;
}



int main() {

   // freopen("in.txt","r",stdin);
    while(true) {
        cin >> row >> col;
        if(row+col==0) return 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cin >> grid[i][j];
            }
        }
        for(int i=0; i<500; i++)
            for(int j=0; j<500; j++) fill(visited[i][j],visited[i][j]+4,false);
        string dir;
        cin >> sx >> sy >> dex >> dey >>  dir;

        if(dir[0]=='n')  pos = 0;
        else if(dir[0]=='e')  pos = 1;
        else if(dir[0]=='w')  pos = 2;
        else pos = 3;
        cout << bfs() << endl;
    }
    return 0;
}


