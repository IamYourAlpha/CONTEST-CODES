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

int main() {
  //   freopen("input.txt","r",stdin);
    int a[1000];
    int b[1000];
    int index[1000];
    bool taken[1000];
    int cont[1000];
    int n;
    int k;
    vector <int> v[1000];
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> a[i];

         v[ a[i] ].push_back(i);
    }
    sort(a,a+n);
    memset(taken,false,sizeof(taken));
    memset(cont,0,sizeof(cont));
    int tot = 0;
    int c = 0;
    for(int i=0; i<n; i++) {
        if(a[i]+tot<=k) {
            tot+=a[i];
            taken[ a[i]  ] = true;
            cont[a[i]]++;
            c++;
        }
    }
    cout << c << endl;
    if(c>=1) {
        for(int i=0; i<1000; i++) {
            if(taken[a[i]]) {
                for(int j=0; j<cont[a[i]]; j++) {
                    cout << v[a[i]][j]+1 << " ";
                    taken[a[i]]= false;
                }

            }
        }
    }
    return 0;
}


