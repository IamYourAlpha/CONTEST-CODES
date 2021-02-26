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


int main() {
    char HH[1000000];
    int tc, len;
    s(tc);
    all(tc) {
        int flag=0;
        ss(HH);
        int k,l;
        int I=0;
            for( k=0, l=strlen(HH)-1 ; k<(strlen(HH)/2),l>(strlen(HH)/2); k++,l--) {
                if(HH[k]==HH[l]) {
                    I++;
                }
            }
            cout<<I<<endl;
            cout<<strlen(HH)<<endl;
            if(strlen(HH)==2) printf("YES\n");
           else if(!(strlen(HH)&1)){
                if(I*2==(strlen(HH))) {
                    printf("YES\n");
                }
                 else if( abs((I*2)-strlen(HH))==2) printf("YES\n");
                else printf("NO\n");
        }
        else {
                if(strlen(HH)==3){ if(HH[1]==HH[0] || HH[1]==HH[2]){ printf("YES\n"); flag=1;}

                else {printf("NO\n"); flag=1;}
                }
                if(I*2==(strlen(HH)) && !flag) {
                    printf("YES\n");
                }
                 else if( abs((I*2)-strlen(HH))==1 || abs((I*2)-strlen(HH))==0  && !flag) printf("YES\n");
                 else if( ((I+1)*2)==strlen(HH) && !flag ) printf("YES\n");
                else if(!flag) printf("NO\n");
        }
    }
        return 0;
}


