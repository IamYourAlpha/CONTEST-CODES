
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


int main() {

      int n;
      while(scanf("%d",&n)!=EOF) {
            if(n==0) return 0;
            if(n==1) {
                  printf("Discarded cards:\nRemaining card: 1\n");
                  continue;
            }
            queue<int>q;
            int demo;
            for(int i=1; i<=n; i++) q.push(i);
            bool ok = false;
             printf("Discarded cards: ");
             printf("%d",q.front());
            q.pop();
            while(q.size()>0) {
                  if(ok) {
                                   printf(", %d",q.front());
                        q.pop();
                        q.push(demo);

                  } else {
                        demo=q.front();
                        q.pop();
                  }
                  ok=!ok;
            }
            printf("\nRemaining card: %d\n",demo);
      }

      return 0;
}


