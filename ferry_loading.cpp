/*** the muffins*****/

using namespace std;
#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
// Input macros

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

queue<int>l,r;
bool visited[1000];

int main() {
     int tc;
     int demo;
     scanf("%d",&tc);
     while(tc--) {
          int len,num;
          string s;
          int c=0;
          double sum=0;
          scanf("%d %d",&len,&num);
          for(int i=0; i<num; i++) {
               cin>>demo;
               cin>>s;
               if(s=="left") l.push(demo);
               if(s=="right") r.push(demo);
          }
          len=len*100;
          bool flag=true;
          // while(!l.empty()) {printf("%d\n",l.front()); l.pop();}
          while( !l.empty() || !r.empty() ) {
               if(flag) {
                    c++;
                    while(!l.empty() && l.front()+sum<=len) {
                         sum=sum+l.front();
                         l.pop();
                    }
                    sum=0;
               } else {
                    c++;
                    while(!r.empty() && r.front()+sum<=len) {
                         sum=sum+r.front();
                         r.pop();
                    }
                    sum=0;
               }
               flag=!flag;
          }
          printf("%d\n",c);
     }
     return 0;
}
