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


int GRID[140][140];
int ans[140][140];
int Co[2]= {1,-1},M,N,R,C;
bool visited[140][140];

bool valid(int x,int y) {
    if(x>=0 && y>=0 && x<R && y<C) return true;
    return false;
}


void DFS(int x,int y) {
       int X,Y;
    if(visited[x][y]) return ;
    visited[x][y]=true;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
             X=Co[i]*M+x;
             Y=Co[j]*N+y;
            if( valid(X,Y) && !GRID[X][Y]) {
                ans[X][Y]++;
                DFS(X,Y);
            }
             X=Co[i]*N+x;
             Y=Co[j]*M+y;
            if(valid(X,Y) && !GRID[X][Y]) {
                ans[x][y]++;
                DFS(X,Y);
            }
        }
    }
}

int main() {
    int n,u,v;
    int tc;
    int k=0;
    scanf("%d",&tc);
    while(tc--) {
        for(int i=0; i<130; i++) {
            for(int j=0; j<130; j++) {
                visited[i][j]=false;
                GRID[i][j]=false;
                ans[i][j]=0;
            }
        }
        cin>>R>>C>>M>>N;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>u>>v;
            GRID[u][v]=true;
        }
        DFS(0,0);
        int even=0;
        int odd=0;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(M==N || N==0 || M==0) ans[i][j]/=2;
               {
                   if(ans[i][j] || (!i && !j)){
                    if(ans[i][j]%2==0) even++;
                    else odd++;
                    cout<<" "<<ans[i][j]<<" ";
                   }
                }
            }
            cout<<endl;
        }
        printf("Case %d: %d %d\n",++k,even,odd);
    }
    return 0;
}

