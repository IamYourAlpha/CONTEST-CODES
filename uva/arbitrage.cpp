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

double matrix[22][22][22];
int parent[22][22][22];
int n;

int main() {
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF) {
    // if(n==0) break;
    //    bool found = false;
        for(int i=0; i<22; i++)
            for(int j=0; j<22; j++)
                for(int k=0; k<22; k++) {
                    matrix[i][j][k] = 0;
                    parent[i][j][k] = -1;
                }
     //   cout << " ok " << endl;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                double u;
                cin >> n;
                if(i == j) matrix[i][j][0] = 1.0;
                else matrix[i][j][0] = u;
            }
        }
   //     cout <<  " OK " << endl;
        for(int level=1; level<n; level++) {
            for(int k =0; k<n; k++) {
                for(int i =0; i<n; i++) {
                    for(int j =0; j<n; j++) {
                        double temp = matrix[i][k][level-1] * matrix[k][j][0];
                        if(temp > matrix[i][j][level]) {
                            matrix[i][j][level] = temp;
                            parent[i][j][level] = k;
                        }
                    }
                }
            }
        }
        int index = -1;
        int len = -1;
        for(int level = 1; level<n; level++) {
            for(int i=0; i<n; i++) {
                if(matrix[i][i][level] > 1.01) {
                    index = i;
                    len = level;
                    break;
                }
            }
            if(index !=-1) break;
        }
        if(index == -1) cout << "no arbitrage sequence exists" << endl;
        else {
       // cout << " p" << endl;
            vector<int>path;
            path.push_back(index);
            int cur = index;
            for(int i = len; i>=0; i--) {
                cur = parent[index][cur][i];
                path.push_back(cur);
            }
            cout << path[path.size() - 1];
            for (int i = path.size() - 2; i >= 0; --i)
                cout << " " << path[i]+1;
            cout << endl;
        }
    }
    return 0;
}
