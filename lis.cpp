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

map<int ,int > mp;
int arr[100];
int arr1[100];
int ans[100];
int n;
int lis() {
      for(int i=1; i<=n; i++) ans [i] = 1;
      for(int i=2; i<=n; i++) {
            for(int j=1; j<i; j++) {
                  if( arr1[j] <   arr1[i]    && ans[ arr1[i] ] < (ans[ arr1[j] ]+1) ) {
                        //      cout << mp[ arr[j] ] << "  " <<  mp[ arr[i] ] << endl;
                        ans [ arr1[i] ] = ans[ arr1[j] ] + 1;
                  }
            }
      }
      int  max_ans = INT_MIN;
      for(int i=1; i<=n; i++) {
            if(ans[i]>max_ans) max_ans = ans[i];
      }
      return max_ans;
}


int main() {
      freopen("input.txt","r",stdin);

      scanf("%d",&n);
      for(int i=1; i<=n; i++) {
            scanf("%d",&arr[i]);
            //  mp[ arr[i] ]=i;
      }
      int demo;
      while( scanf("%d",&demo)!=EOF) {
            arr1[demo] = arr[1];
            for(int i=2; i<=n; i++) {
                  scanf("%d",&demo);
                  arr1[demo]=arr[i];
            }
            printf("%d\n",lis());
            for(int i=0; i<100; i++) {
                  ans[i]=0;
            }
            //     for(int i=1; i<=n; i++) printf("%d ",mp[ arr[i] ]);
            //       cout << endl;
            //        for(int i=1; i<=n; i++) printf("%d ",mp[ arr1[i] ]);
            //    cout << endl;

      }
      //        for(int i=1;i<=n;i++) cout << mp[ arr[i] ] << endl;
      return 0;
}
