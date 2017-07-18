
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

struct state {
    state(int now,int need) : now(now) , need(need) {}
    bool operator<(const state & other) const {
        return need>other.need;
    }
    int need,now;
};

vector< int > graph[1000];
int dist[10000];
int need[1000][1000];
int n;
map< string , int >mp;
void dijkstra(int source,int destination) {
    for(int i=1; i<=100; i++) dist[i]=99999;
    dist[source] = 0;
    priority_queue<state>pq;
    pq.push(state(source,0));
    while(!pq.empty()) {
        int now = pq.top().now;
        int use = pq.top().need;
        //   cout << use << endl;
        pq.pop();
        //if(now == destination) break;
        for(int i=0; i<graph[now].size(); i++) {
            cout << use << endl;
            if(need [now] [ graph[now][i] ] + use < dist[ graph[now][i] ]) {
                dist[ graph[now][i] ] = need [now] [ graph[now][i]  ] + use;
                pq.push(state(graph[now][i],dist[ graph[now][i] ]));
            }
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    int n;
    int index=0;
    while(scanf("%d",&n)!=EOF) {
        if(n==0) return 0;
        string s,d;
        cin >> s >> d;
        for(int i=0; i<n; i++) {
            string demo1;
            string demo2;
            string demo3;
            cin >> demo1 >> demo2 >> demo3 ;
            if(mp[demo1]==0) {
                index++;
                mp[demo1] = index;
            }
            if(!mp[demo2]) {
                index++;
                mp[demo2] = index;
            }
            graph[ mp[demo1] ].push_back( mp[demo2] );
            graph[ mp[demo2] ].push_back( mp[demo1] );

            if( !need[ mp[demo1] ][ mp[demo2] ]) demo3.length();
            need[ mp[demo2] ][ mp[demo1] ] = demo3.length();
            //         cout << mp[demo1] << " " << mp[demo2] << " " << demo3.length() << endl;
        }
        dijkstra(mp[s],mp[d]);
        //  for(int i=1;i<=n;i++) cout << dist[i] << endl;
        cout << dist[ mp[d] ]  << endl;
    }
    return 0;
}

