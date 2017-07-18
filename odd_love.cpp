using namespace std;
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
#include<math.h>
#include<queue>
#include<cstdlib>
#include<ctype.h>
#include<string>
#include<cstdio>
#include<algorithm>

/**********INPUT******/
#define sint(a)     scanf("%d",&a)
#define pint(a)     printf("%d",a)
//#define sintll(a)   scanf("%lld",&a)
//#define pintll(a)   printf("%lld",a)
//#define sint2(a,b)  scanf("%d%d",&a,&b)


#define MAX(a,b) (a > b) ? (a) : (b)
#define MIN(a,b) (a < b) ? (a) : (b)
#define MIN3(a,b,c) (a < b) ? (a < c ? a : c) : (b < c ? b : c)
#define MAX3(a,b,c) (a > b) ? (a > c ? a : c) : (b > c ? b : c)
#define mem(x,y) memset(x,y,sizeof(x));
#define pb push_back
#define pf pop_front()
#define N 1000000+7


/* loops****/
#define rep(a,n) for(int a=1;a<=n;a++)
#define repo(a,n) for(int a=0;a<n;a++)

#define PINF 2147483647
#define NINF -2147483647
#define Pi acos(-1.0)
typedef struct {
    int eX;
    int eY;
} node;

node cur,now;
queue<node>q;

char Grid[100][100];
int step[100][100];
int r,c,ven;
int visited[100][100];
int dirx[] = {0,0,+1};
int diry[] = {+1,-1,0};

int ok(int x,int y) {
    if(x>=0 && x<c && y>=0 && y<r) return true;
    return false;
}

int bfs(int x,int y) {
    cur.eX = x;
    cur.eY = y;
    step[x][y] = 0;
    q.push(cur);
    memset(visited,false,sizeof(visited));
       memset(step,0,sizeof(step));
    while(!q.empty()) {
        cur = q.front();
        q.pop();
	//cout << "steps:  " << Grid[cur.eX][cur.eY] << endl;
        //visited[now.eX][now.eY] = true;
        if(ven==0)  return step[cur.eX][cur.eY];
        for(int i=0; i<=2; i++) {
       //   cout << "ok " << endl;
            int XX = cur.eX + dirx[i];
            int YY = cur.eY + diry[i];
            if(ok(XX,YY) && !visited[XX][YY]) {
                visited[XX][YY] =  true;
                step[XX][YY] = step[cur.eX][cur.eX] + 1;
                now.eX = XX;
                now.eY = YY;
                q.push(now);
                int demo = Grid[XX][YY]-'0';
                if(!(demo&1)) ven--;
           //     cout << ven << endl;
            }
        }
    }
    return 0;
}

int main() {
    int tc;
    freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    while(tc--) {
        ven = 0;
        scanf("%d%d",&r,&c);

        for(int i=0; i<c; i++)
            cin >> Grid[i];
        for(int i=0; i<c; i++) {
            for(int j=0; j<r; j++) {
            int demo = Grid[i][j]-'0';
                if(!(demo&1)) ven++;
            }
        }
      // cout << ven << endl;
        int ans = bfs(0,0);
         printf("%d\n",ans);
        //cout << ven << endl;

    }
    return 0;
}

