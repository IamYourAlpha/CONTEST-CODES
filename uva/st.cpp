
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
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        prllf("%d\n",n)
#define ps(n)                       prllf("%s\n",n)
#define pl(n)                       prllf("%lld\n",n);

// Useful constants
#define INF                         (ll)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define all(n)                      for(ll i=0;i<n;i++)
#define alls(m)                      for(ll j=0;j<m;j++)
#define rep(i,a,b)                   for(ll i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all1(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((ll)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

//STL output ***************
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)


int main() {

                vector<ll> set_A;
                vector<ll> set_B;

                bool found=false;
                ll key,key1;
                ll n;

                scanf("%lld",&n);

                for(ll i=0; i<n; i++) {
                                scanf("%lld",&key);
                                set_A.pb(key);
                                scanf("%lld",&key);
                                set_B.pb(key);
                }


                bool visited[1000000];
                memset(visited,false,sizeof(visited));
                for(ll i=0; i<n; i++) {
                                for(ll j=0; j<n; j++) {
                                                if(set_A[i]==set_B[j]) {
                                                                visited[ set_A[i] ]=true;
                                                                found=true;
                                                                break;
                                                }
                                }
                                if(found==false) {
                                                key=set_A[i];
                                                break;
                                } else found = false;
                }
                for(ll i=0; i<n; i++) if(!visited[set_B[i]]) key1=set_B[i];




                /*
                for(ll i=0; i<n; i++) {
                    for(ll j=0; j<n; j++) {
                        if(set_A[i]==set_B[j]) {
                            found=true;
                            break;
                        }
                    }
                    if(found==false) {
                        key=set_A[i];
                        break;
                    } else found = false;
                }

                found=false;
                for(ll i=0; i<n; i++) {
                    for(ll j=0; j<n; j++) {
                        if(set_A[j]==set_B[i]) {
                            found=true;
                            break;
                        }
                    }
                    if(found==false) {
                        key1=set_B[i];
                        break;
                    } else found = false;
                }
                */
//   prllf(" %d ",key1);


                queue<ll>q;
                q.push(0);
                q.push(key);
                printf("%lld ",key);
                printf("%lld\n",key1);
                ll  flag=0;
                ll  flag_=0;
                memset(visited,false,sizeof(visited));
                while(true) {
                                for(ll i=0; i<n; i++) {
                                                ll demo=q.front();
                                                //  if(set_A[i]==0){ flag_=1; break;}
                                                if(demo==set_A[i] && !visited[demo]) {
                                                                q.push(set_B[i]);
                                                                if(q.front()!=0) {
                                                                                printf("%d ",q.front());
                                                                                flag++;
                                                                }
                                                                q.pop();
                                                                if(flag==(n-1)) {
                                                                                flag_=1;
                                                                                break;
                                                                }
                                                }
                                }
                                if(flag_) break;
                }
                printf("%lld",key1);
                return 0;

}
