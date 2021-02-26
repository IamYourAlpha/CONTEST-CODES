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
#include<conio.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        printf("%d\n",n)
#define ps(n)                       printf("%s\n",n)
#define pl(n)                       printf("%lld\n",n);

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define all(n)                      for(int i=0;i<n;i++)
#define alls(m)                      for(int j=0;j<m;j++)
#define rep(i,a,b)                   for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all1(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())


#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)

int g[100][100];
int visted[100][100];
int R,C,M,N,W;
int grid_ans[100][100];
bool valid(int tx,int ty) {
    if(tx>=0 && ty>=0 && tx<R && ty<C)
        return true;
    return false;
}

void BFS(int x,int y) {
    int tx;
    int ty;
    int dx[8] = {M,M,-M,-M,N,N,-N,-N};
    int dy[8] = {N,-N,N,-N,M,-M,M,-M};
    int ans=0;
    queue<int>node1;
    queue<int>node2;
    node1.push(x);
    node2.push(y);
    grid_ans[x][y]=-1;
    while(!node1.empty() && !node2.empty() ) {
        set<pair<int,int> >S;
        int X=node1.front();
        int Y= node2.front();
        node1.pop();
        node2.pop();
        for(int i=0; i<8; i++) {
            tx= dx[i]+X;
            ty= dy[i]+Y;
            if( valid(tx,ty) ) {
                if( g[tx][ty]!=1 &&  S.find(make_pair(tx, ty)) == S.end() ) {
                    ans++;
                    S.insert(mp(tx,ty));
                }
                if( g[tx][ty]==0 ) {
                    g[tx][ty]=-1;
                    node1.push(tx);
                    node2.push(ty);
                }
            }
        }
        grid_ans[X][Y]=ans;
    }
}

int main() {
    int tc;
    int u,v;
    s(tc);
    int k=0;
    while(tc--) {
        int even=0;
        int odd=0;
        cin>>R>>C>>M>>N>>W;
        all(W) {
            s(u);
            s(v);
            g[u][v]=1;
            g[v][u]=1;
        }

        BFS(0,0);
        if(grid_ans[0][0]==0) grid_ans[0][0]=2;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(grid_ans[i][j]) {
                    if(grid_ans[i][j]&1) {
                        odd++;
                    } else even++;
                }
            }
        }
        printf("Case %d: %d %d\n", ++k, even, odd);

    }
    return 0;
}
