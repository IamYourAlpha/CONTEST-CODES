
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

int dp[500000];

void prepos() {
      dp[0]=0;
      dp[1]=1;
      dp[2]=2;
      dp[3]=2;
      int temp=1;
      int temp1=2;
      int demo=2;
      for(int i=3; i<=500000; i++) {
            if(temp<=temp1) {
                  dp[i]=demo;
                  demo+=2;
                  temp++;
            } else {
                  dp[i]=2;
                  temp=2;
                  demo=4;
                  temp1*=2;

            }
      }
}

int main() {
      int n;

      prepos();
      while(scanf("%d",&n)==1) {
            if(n==0) return 0;
            printf("%d\n",dp[n]);
      }
      return 0;
}
