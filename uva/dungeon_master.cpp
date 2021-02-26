using namespace std;
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>


typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vector< vector<char> > > vvi;

typedef struct state {
    int x,y,z;
} node;

//int positionx[6] = {0,0,0,-1,0,1};
//int positiony[6] = {0,0,-1,0,1,0};
//int positionz[6] = {1,-1,0,0,0,0};

int positionx[6]= {0,0,0,-1,0,1};
int positiony[6]= {0,0,-1,0,1,0};
int positionz[6]= {1,-1,0,0,0,0};
int L,R,C;
node now,start,ext,top;
int visited [100][100][100];

bool valid(int lev,int row,int col,vector< vector< vector<char> > > *grid) {
    if(lev >=0 && lev<L && row<R && row>=0 && col<C && col>=0)
        return ( grid->at(lev)[row][col] =='.' || grid->at(lev)[row][col]=='E') ? true:false;
    else return false;
}

int bfs(node start,node ext,vector<vector<vector<char> > > *grid) {
    queue <node> q;
    q.push(start);
    memset(visited,-1,sizeof(visited));
    visited[start.z][start.x][start.y] = 0;
    while(!q.empty()) {
       node top = q.front();
        q.pop();
        if(top.x == ext.x && top.y == ext.y && top.z == ext.z ) return visited[top.z][top.x][top.y];
        for(int i=0; i<6; i++) {
            int nex = top.x + positionx[i];
            int ney = top.y + positiony[i];
            int nez = top.z + positionz[i];
            if(  valid(nez,nex,ney,grid) && visited [nez][nex][ney]==-1 ) {
          //  cout << " here " << endl;
                visited [nez][nex][ney] = visited [top.z][top.x][top.y] + 1;
                now.x = nex;
                now.y = ney;
                now.z = nez;
        //        cout << visited [nez][nex][ney] << endl;
                q.push(now);
            }
        }
    }
    return -1;
}

int main() {
//      freopen("input.txt","r",stdin);

    while(scanf("%d %d %d",&L,&R,&C)==3) {
        if(L+R+C ==0) return 0;
        vector< vector< vector<char> > > grid;
        for(int l=0; l<L; l++) {
            vector <  vector<char> > level;
            for(int i=0; i<R; i++) {
                vector <char> rw;
                for(int j=0; j<C; j++) {
                    char demo;
                    cin >> demo;
                    if(demo == 'S') {
                        start.x = i;
                        start.y = j;
                        start.z = l;
                    }
                    if(demo == 'E') {
                        ext.x = i;
                        ext.y = j;
                        ext.z = l;
                    }
                    rw.push_back(demo);
                }
                level.push_back(rw);
            }
            grid.push_back(level);
            }
           // cout << ext.x << " " << ext.y << " " << ext.z << endl;
        int ans = bfs(start,ext,&grid);
        (ans == -1)?printf("Trapped!\n"):printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
