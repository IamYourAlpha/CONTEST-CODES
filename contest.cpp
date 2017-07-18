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

int arr[100000+10];
int  ans[100000+10];
int nn;
int lis() {
     int ans_so_far = 0;
     int ans = 0;
       for (int i = 0; i < nn-1; i++ ){
       if ( arr[i] <= arr[i+1]) ans++;
       else ans = 0;
       ans_so_far = max(ans_so_far,ans);
       }
       return ans_so_far;
}


int main() {
     freopen("input.txt","r",stdin);

      scanf("%lld",&nn);
      for(int i=0; i<nn; i++)
            scanf("%d",&arr[i]);
            int tot  = lis();
            cout << tot+1 << endl;

      return 0;
}
