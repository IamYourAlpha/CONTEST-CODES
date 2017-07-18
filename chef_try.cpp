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


char n[100000];
ll SUPER_SONIC(ll F,ll L) {
    ll ret2=0;
    if(F>L || L<0) return 0;
    if(F==L) return 0;
    //  if(dp[F][L]!=-1 && abs(demo-dp[F][L])>1) return 0;
   // if(dp[F][L]!=-1) return dp[F][L];
    if(n[F]==n[L])  return ret2=0+SUPER_SONIC(F+1,L-1);
    else{
    ret2= 1+SUPER_SONIC(F,L-1);
    ret2=max(ret2,1+ SUPER_SONIC(F+1,L));
    }
    //dp[F][L]= max(dp[F+1][L],dp[F][L-1]);
    return ret2;
}

int main() {
    int tc, len,i;
    scanf("%d",&tc);
    while (tc--) {
 //       memset(dp,-1,sizeof(dp));
        scanf("%s",n);
        int len2=SUPER_SONIC(0,strlen(n));
        // cout<<len2<<endl;
        int len=strlen(n);
        //cout<<len<<endl;
        if(len2<=1) printf("YES\n");
        else printf("NO\n");        /*
          for (i = len -1; i >= 0; --i) {
              for (int j =0; j < len; ++j) {
                  if (str[i] == str[j]) dp[i][j] = dp[i + 1][j - 1];
                                  else {
                      dp[i][j] = dp[i -1][j];
                      dp[i][j]=dp[i][j +1]
                               dp[i][j]==dp[i-1][j+1]

                                          }
              }
              */
    }
    return 0;
}
