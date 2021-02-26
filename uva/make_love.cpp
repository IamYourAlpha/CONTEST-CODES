#include<bits/stdc++.h>
using namespace std;

struct ss {
    char letter;
    int cnt;
} S[2000];



int row,col;
char graph[100][100];
int tot;
int len;
void dfs(int x, int y,char demo) {
    if(x>=row || x<0 || y>=col || y<0 || graph[x][y]=='.' || graph[x][y]!=demo) return;
    tot++;
    graph[x][y] = '.';
    dfs(x+1,y,demo);
    dfs(x,y-1,demo);
    dfs(x,y+1,demo);
    dfs(x-1,y,demo);
}


bool comp(ss x,ss y) {
    if( x.cnt > y.cnt ) return true;
    else if(x.cnt == y.cnt && x.letter<y.letter ) return true;
    else return false;
}



int main() {
    int k =0;
freopen("in.txt","r",stdin);
    while(cin >> row >> col) {
        if(row+col==0) return 0;
        // for(int i=0; i<100; i++)

        //   for(int j=0; j<100; j++) visited[i][j] = false;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cin >> graph[i][j];
            }
        }
        len = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(graph[i][j] != '.')
                    S[len].letter = graph[i][j];
                dfs(i,j,graph[i][j]);
                S[len].cnt = tot;
                len++;
                tot = 0;
            }
        }
        sort(S,S+len,comp);
        cout << "Problem " << ++k <<":" << endl;
        for(int i=0; i<len; i++) if(S[i].cnt!=0) cout << S[i].letter << " " << S[i].cnt<< endl;
        len = 0;
    }
    return 0;

}
