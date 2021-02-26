
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

int main() {

      int tc;
      int k=0;
      scanf("%d",&tc);
      getchar();
      while(tc--) {
            string s1;
            char ch;
            while(true) {
                  scanf("%c",&ch);
                  if(isalpha(ch)) {
                        s1+=ch;

                  }
                  if(ch=='\n') break;
            }

string s2=s1;
reverse(s1.begin(),s1.end());
int dimen = s1.length();
if( sqrt(dimen)-(int)sqrt(dimen)==0 && s1==s2) printf("Case #%d:\n%d\n",++k,(int)sqrt(dimen));
else printf("Case #%d:\nNo magic :(\n",++k);

      }
      return 0;
}
