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
typedef vector< vector< vector<char> > > vvi;

typedef struct state {
    state(int x,int y,int z) : x(x) , y(y) , z(z) , time(time)  {}
    int x,y,z;
}node;

int positionx = {-1,+1,0,0,0,0};
int positiony = {0,0,-1,+1,0,0};
int positionz = {0,0,0,0,1,-1};
