

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
#define ll long long


ll n;
double dp[100];
void nPr(ll n) {
      dp[0]=1;
      dp[1]=1;
      for(int i=2; i<=n; i++)
            dp[i]=i*dp[i-1];
}

int main() {
      nPr(13);
      int tc;
      ll tot;
      scanf("%d",&tc);
      double sign=1;
      while(tc--) {
            tot=0;
            scanf("%lld",&n);
            double ans=0.00;
            for(int i=2; i<=n; i++) {
                  ans+=double( (sign)*(double)(1/dp[i]));
                  sign*=-1;
            }
            printf("%.lf/%.lf\n",abs(dp[n]*ans),dp[n]);

      }
      return 0;
}
