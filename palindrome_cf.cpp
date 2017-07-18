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


int main() {
    bool red[1000];
    int need;
    string s;
    string demo;

    cin >> s;
    demo = s;
    reverse(s.begin(),s.end());
    int pos;
    int cnt=0;
    int in;
    if(demo==s) {
        for( in=0; in<demo.length(); in++) {
            if(in==demo.length()/2) cout << demo[demo.length()/2];
            cout << demo[in];
        }
        return 0;
    }
    bool flag = true;

    for(int i=0; i<1000; i++) red[i] = false;
    for(int k=0; k<demo.length(); k++) {
        //  cout <<"fast:"<< k << endl;
        red[k] = true;
        flag = true;
        for(int i=0,j=demo.length()-1; i<demo.length()/2; i++,j--) {
            if(red[i]) i++;
            if(red[j]) j--;
            if(demo[i]!=demo[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            need = k;
            break;
        }
        red[k] = false;
        if(flag) break;
        //    cout <<"last:"<< k << endl;
    }
//   for(int i=0; i<demo.length(); i++) if(red[i]) cnt++;
    if(flag==false) {
        printf("NA\n");
        return 0;
    }
    bool printed = false;
    int len = demo.length()-1;
    for(int i=0; i<demo.length(); i++) {

        if(i+need==len && !printed && need<i) {
            cout << demo[i];
            cout <<demo[need];
            printed=true;
        } else if(i+need==len && !printed && need>i) {
            cout << demo[need];
            cout <<demo[i];
            printed=true;
        } else cout << demo[i];

    }

    // cout << demo[i] << " " << demo[j] << endl;

    return 0; //if(s==demo) printf("ok");
}
