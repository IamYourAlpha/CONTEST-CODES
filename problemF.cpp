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


// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())


int tot;
int c;
int final_ans;

string str[1000];
char ch;
map<string,int>mp;
map<char,bool>visited;

void reset_() {
      visited[ '1' ]=false;
      visited[ '2' ]=false;
      visited[ '3' ]=false;
      visited[ '4' ]=false;
      visited[ '5' ]=false;
      visited[ '6' ]=false;
      visited[ '7' ]=false;
      visited[ '8' ]=false;
      visited[ '9' ]=false;
      // visited[ 'j' ]=false;
      c=0;
      tot=0;
}

int main() {


      int n;
      int k=0;
  //   freopen("input.txt","r",stdin);

      while(scanf("%d",&n)!=EOF) {
            if(n==0) return 0;
            final_ans=-1;
            reset_();
            for(int i=0; i<n; i++) {
                  for(int j=0; j<3; j++) {
                        cin>>ch;
                        str[i]+=ch;
                  }
                  int demo;
                  scanf("%d",&demo);
                  mp[ str[i] ] = demo;
            }
            for(int i=0; i<n; i++) {
                      reset_();
                  visited[str[i][0]]=true;
                  visited[str[i][1]]=true;
                  visited[str[i][2]]=true;
                  tot=mp[ str[i] ];
                  c=3;
                  for(int j=0; j<n; j++) {
                        if(i!=j) {
                              if(!visited[str[j][0]] &&  !visited[str[j][1]] &&  !visited[str[j][2]]) {
                                    tot+= mp[ str[j] ];
                                    visited[str[j][0]]=true;
                                    visited[str[j][1]]=true;
                                    visited[str[j][2]]=true;
                                    c+=3;

                                    if(c==9) {

                                          final_ans= max(final_ans,tot);
                                          c=0;
                                          break;

                                    }

                              }
                        }
                  }

            }

            printf("Case %d: %d\n",++k,final_ans);
            reset_();
            mp.clear();
            for(int i=0; i<1000; i++) str[i].clear();

      }
      return 0;
}
