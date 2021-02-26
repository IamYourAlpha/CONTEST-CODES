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

vector< pii > in2[10000];
bool visited[10000];
int vertex;
int edges;

struct state {
    int node,cl;
    state(int node,int cl) :  cl(cl), node(node) {}
    state();
};

bool bfs(int s,int d,int color) {
    visited[s] = true;
    queue < state > q;
    q.push( state(s,color) );
    while(!q.empty()) {
        if(q.front().node == d) return true;
        int now = q.front().node;
        q.pop();
        for(int i=0; i<in2[now].size(); i++) {
            pii ref_ = in2[now][i];
            int nd = ref_.first;
            int rong = ref_.second;
           // cout << nd << " " <<  rong << endl;
            if(!visited[nd] && rong == color) {
                visited[nd] = true;
                q.push(state(nd,rong));
            }
        }
    }
    return false;
}


int main() {
    freopen("input.txt","r",stdin);
    int ans = 0;
    int u,v,c;
    cin >> vertex >> edges ;

    for(int i=0; i<edges; i++) {
        cin >> u >> v >> c;
        in2[u].push_back(make_pair(v,c));
        in2[v].push_back(make_pair(u,c));
    }
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        ans = 0;
        cin >> u >> v;
        for(int j=1; j<=100; j++) {
            memset(visited,false,sizeof(visited));
            if(bfs(u,v,j))
            ans++;
            //taken[j] = true;
        //    cout << "pause" << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
