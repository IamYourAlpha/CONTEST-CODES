/*************************

Author : Md Intisar Chowdhury
Inst : Ahasanullah University of Science And Tech
Do not use or copy the code without persmission.

*****************************************/


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

/*typedef struct state {
    state(int x,int y,int z) : x(x) , y(y) , z(z) , time(time)  {}
    int x,y,z;
} node;
*/
int positionx[] = {-1,+1,0,0,0,0};
int positiony[] = {0,0,-1,+1,0,0};
int positionz[] = {0,0,0,0,1,-1};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int M,N;
char MN[50][50],land;
bool visited[50][50];

int dfs(int i,int j) {
    if(!visited[i][j]) {
        if( i<N && i>=0 && MN[i][j] == land) {
            int ns = 1;
            for(int i=0; i<4; i++) {
                int x = (i + dx[i]);
                int y = (j + dy[i])%M;
                ns = ns + dfs(i,j);
                return ns;
            }
        } else return 0;
    }
    return 0;
}

int main() {
  //  freopen("input.txt","r",stdin);
    while(scanf("%d %d",&N,&M)!=EOF) {
      memset(visited,false,sizeof(visited));
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                getchar();
                char ch = getchar();
                MN[i][j] = ch;
            }
        }
        int gx,gy;
        scanf("%d %d",&gx,&gy);
        land = MN[gx][gy];
        int ans = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(MN[i][j] == land)
                    ans = max(ans,dfs(i,j));
            }
        }
    }
    return 0;
}
