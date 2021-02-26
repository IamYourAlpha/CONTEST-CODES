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


int memo[1000][1000];
char f[10000];
char s[10000];

int lcs(int m,int n) {
      for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                  if(i==0 || j==0) memo[i][j]=0;
                  else if(f[i-1]==s[j-1]) memo[i][j]=memo[i-1][j-1]+1;
                  else {
                        memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
                  }
            }
      }
      return memo[m][n];
}


int main() {
      int tc=0;
      while(gets(f)  && f[0]!='#') {
            gets(s);
            for(int i=0; i<100; i++)
                  for(int j=0; j<100; j++) memo[i][j]=0;
            int  ans = lcs(strlen(f),strlen(s));
            printf("Case #%d: you can visit at most %d cities.\n",++tc,ans);
      }
      return 0;
}
