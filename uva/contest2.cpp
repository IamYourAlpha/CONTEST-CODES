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

struct node {
    int cash;
    int factor;
} frnd[100000+100];

bool myfun(node a,node b) {
    return a.factor > b.factor;
}

vi take;
int n,d;
set<int>s;

int main(){
  vector<int>v;
  for(int i=1;i<=5;i++) v.push_back(i);
  for(int i=0;i<v.size();i++) cout << v [ i ]  <<" " ;
  cout << endl;

  int anss = lower_bound (v.begin(),v.end(),5)- v.begin();
  int ans = upper_bound (v.begin(),v.end(),5)- v.begin();
  cout << ans << endl;
  cout << anss << endl;
  }
