/************************************ MINIMUM VERTEX COVER ************************************************/
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

typedef vector<int> vi;

bool seen[1000];
int v,e;
vector <int> graph[100];


void MVC() {
    for(int i=0; i<v; i++) seen [i] = false;
    for(int i=0; i<v; i++) {
        if(!seen[i]) {
            for(int j=0; j<graph[i].size(); j++) {
                if(!seen [ graph[i][j] ] ) {
                    seen [ graph[i][j] ] = true;
                    seen [ i ] = true;
                    break;
                }
            }
        }
    }
      for(int i=0;i<v;i++) if(seen[i]) cout << i << " ";
      cout << endl;
}


int main() {

    cout << "enter the number of edges" << endl;
    cin >> e;
    cout << "enter the number of vertex" << endl;
    cin >> v;
    for(int i=0; i<e; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    MVC();
    return 0;
}





