#include<bits/stdc++.h>
using namespace std;

int graph[200][200];
int row,col;
string name;

int memo[200][200];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int ans ;
int m,n;

int dp(int i,int j) {
    if(memo[i][j]>=0) return memo[i][j];
    int tot = 1;
    for(int k=0; k<4; k++) {
       int x = i + dx[k];
       int y = j + dy[k];
        if(graph[x][y]<graph[i][j]) {
            tot = max( tot,dp(x,y)+1 );
        }
    }
    return (memo[i][j] = tot);

}

int main() {
 freopen("in.txt","r",stdin);

    int tc;
    cin >> tc;
    while(tc--) {
        cin >> name;
        cin >> m >> n;
        memset(graph,1,sizeof(graph));

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                cin >> graph[i][j];
            }
        }
        ans = 0;
        memset(memo,-1,sizeof(memo));
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                ans = max ( ans, dp(i,j));
            }
        }

        cout << name << ": "<< ans << endl;
    }
    return 0;
}
