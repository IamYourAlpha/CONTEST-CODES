
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

vector< ll > in[1000000];

int main() {
      ll n,q;
      ll  demo;
      // freopen("input.txt","r",stdin);
      while(scanf("%lld %lld",&n,&q)!=EOF) {
            // memset(in,0,sizeof(in));
            for(ll i=1; i<=n; i++) {
                  scanf("%lld",&demo);
                  in[demo].push_back(i);
            }
//cout << in[3][0]<<endl;
            for(ll i=0; i<q; i++) {
                  ll k,v;
                  scanf("%lld %lld",&k,&v);
                  if(in[v].size()<k) printf("0\n");
                  // cout << k << v << endl;
                  else                    printf("%lld\n",in[v][k-1]);
            }
            for(ll i=0; i<=1000000; i++) in[i].clear();
      }
      return 0;
}
