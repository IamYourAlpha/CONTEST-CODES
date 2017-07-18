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

int AA[5000+2];
map<int,bool>mp;
bool visited[5000+2];

void reset() {
	mp[1]=true;
	mp[2]=true;
	mp[3]=true;
	}

int main() {
	int n;
	int A[5000+2];
	scanf("%d",&n);
	memset(visited,false,sizeof(visited));
	for(int i=1; i<=n; i++) {
			scanf("%d",& A[ i ]);
			AA[ A[ i ] ]++;
			}

	int  ans= min(  AA[ 1 ] ,min( AA[ 2 ], AA[ 3 ] )  );

	printf("%d\n",ans);
 int c=0;
	bool ok=false;
	for(int j=1; j<=ans; j++) {
			reset();
			if(ok) printf("\n");
			ok=true;
			for(int i=1; i<=n; i++) {
					if(  visited[ i ]==false && mp[ A[ i ] ]==true ) {
							printf("%d ",i);
							mp[ A[ i ] ]=false;
                            visited[ i ]=true;
							c++;
							if(c==3) break;
							}
					}
			}
	return 0;
	}
