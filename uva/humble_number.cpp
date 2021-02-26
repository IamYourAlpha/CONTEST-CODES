
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

//STL output ********************************
template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) {
                return os << "(" << p.first << ", " << p.second << ")";
}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v) {
                bool first=true;
                os<<"[";
                for(unsigned int i=0; i<v.size(); i++) {
                                if(!first)os<<", ";
                                os<<v[i];
                                first=false;
                }
                return os<<"]";
}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v) {
                bool first=true;
                os << "[";
                for(typename std::set<T>::const_iterator ii=v.begin(); ii!=v.end(); ++ii) {
                                if(!first)os<<", ";
                                os<<*ii;
                                first=false;
                }
                return os<<"]";
}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) {
                bool first = true;
                os << "[";
                for (typename std::map<T1,T2>::const_iterator ii =v.begin(); ii!=v.end(); ++ii) {
                                if(!first)os<<", ";
                                os<<*ii;
                                first=false;
                }
                return os<<"]";
}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0) {
                for(T2 i=beg; i<sz; i++) cout<<a[i]<<" ";
}

#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)

inline ll binpow(ll x,ll n) {
                ll res=1;
                while(n) {
                                if(n&1)res*=x;
                                x*=x;
                                n>>=1;
                }
                return res;
}
inline ll powmod(ll x,ll n, ll _mod) {
                ll res=1;
                while(n) {
                                if(n&1)res=(res*x)%_mod;
                                x=(x*x)%_mod;
                                n>>=1;
                }
                return res;
}
inline ll mulmod(ll x,ll n, ll _mod) {
                ll res=0;
                while(n) {
                                if(n&1)res=(res+x)%_mod;
                                x=(x+x)%_mod;
                                n>>=1;
                }
                return res;
}
inline ll gcd(ll a,ll b) {
                ll t;
                while(b) {
                                a=a%b;
                                t=a;
                                a=b;
                                b=t;
                }
                return a;
}
inline int gcd(int a,int b) {
                int t;
                while(b) {
                                a=a%b;
                                t=a;
                                a=b;
                                b=t;
                }
                return a;
}
inline ll lcm(int a,int b) {
                return a/gcd(a,b)*(ll)b;
}
inline ll lcm(ll a,ll b) {
                return a/gcd(a,b)*b;
}
inline ll gcd(ll a,ll b,ll c) {
                return gcd(gcd(a,b),c);
}
inline int gcd(int a,int b,int c) {
                return gcd(gcd(a,b),c);
}
inline ll lcm(ll a,ll b,ll c) {
                return lcm(lcm(a,b),c);
}
inline ll lcm(int a,int b,int c) {
                return lcm(lcm(a,b),(ll)c);
}

inline ll max(ll a,ll b) {
                return (a>b)?a:b;
}
inline int max(int a,int b) {
                return (a>b)?a:b;
}
inline double max(double a,double b) {
                return (a>b)?a:b;
}
inline ll max(ll a,ll b,ll c) {
                return max(a,max(b,c));
}
inline int max(int a,int b,int c) {
                return max(a,max(b,c));
}
inline double max(double a,double b,double c) {
                return max(a,max(b,c));
}
inline ll min(ll a,ll b) {
                return (a<b)?a:b;
}
inline int min(int a,int b) {
                return (a<b)?a:b;
}
inline double min(double a,double b) {
                return (a<b)?a:b;
}
inline ll min(ll a,ll b,ll c) {
                return min(a,min(b,c));
}
inline int min(int a,int b,int c) {
                return min(a,min(b,c));
}
inline double min(double a,double b,double c) {
                return min(a,min(b,c));
}





ll happy[60000+10];

void prepos() {
                int pow_[4]= {1,1,1,1};
                int num[4]= {2,3,5,7};
                happy[1]=1;
                for(int i=2; i<=60000; i++) {
                                happy[i]= min( 2*happy[ pow_[0] ], min(3*happy[ pow_[1] ],min( 5*happy[ pow_[2] ], 7*happy[ pow_[3] ]) ) );
                                for(int j=0; j<4; j++) {
                                                if(happy[i]==( num[j]*happy[ pow_[j] ])) pow_[j]++;
                                }
                }
                //for(int i=0;i<100;i++) printf("%lld\n",happy[i]);}
}

int main() {
                char numq[1000];
                char print[1000];
                prepos();
                while (scanf("%s",numq)==1) {
                                if(!strcmp(numq,"0")) return 0;
                                ll  numenq=atoi(numq);

                                if (numenq==0) break;

                                if (numq[strlen(numq)-1]=='1'&&numq[strlen(numq)-2]!='1') strcpy(print,"st");
                                else if (numq[strlen(numq)-1]=='2'&&numq[strlen(numq)-2]!='1') strcpy(print,"nd");
                                else if (numq[strlen(numq)-1]=='3'&&numq[strlen(numq)-2]!='1') strcpy(print,"rd");
                                else strcpy(print,"th");

                                printf("The %lld%s humble number is %lld.\n",numenq,print,happy[numenq]);
                }

                return 0;

}


