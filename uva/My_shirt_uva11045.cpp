// =====================================================================================
//
//       Filename:  My_shirt_uva11045.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  02/28/2016 01:02:59 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  INTISAR (),
//   Organization:
//
// =====================================================================================


using namespace std;
#include <bits/stdc++.h>

#define _MAX_ 300
#define inf 999999
#define debug cout << " debuging " << endl
int grid [_MAX_][_MAX_];
int mf,f,source=0,sink;
vector<int> parent;
int m,n;
void augment(int v,int minf) {
    if( v == source ) {
        f = minf;
        return;
    } else if ( parent[v] != -1 ) {
        augment( parent[v], min ( minf, grid[parent[v]][v]  ) );
        grid[ parent[v]][v]-= f;
        grid[v][parent[v]]+= f;
    }
    return;
}

int main() {
    freopen("input.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    while( tc-- ) {
        scanf("%d %d",&n,&m);
        memset(grid,0,sizeof(grid));
        for( int i = 1; i <= 6; i++) grid [0][i] = n/6;
        for( int i = 7; i < 7+m; i++) grid[i][7+m] = 1;
        for(int i = 7; i < 7+m; i++) {
            //cout << " debug " << endl;
            string syz;
            cin >> syz;
            if( syz == "XXL" ) grid[1][i] = 1;
            else if( syz == "XL"  ) grid[2][i] = 1;
            else if( syz == "L"  ) grid[3][i] = 1;
            else if( syz == "M"  ) grid[4][i] = 1;
            else if( syz == "S"  ) grid[5][i] = 1;
            else if( syz == "XS"  ) grid[6][i] = 1;
            cin >> syz;
            if( syz == "XXL" ) grid[1][i] = 1;
            else if( syz == "XL"  ) grid[2][i] = 1;
            else if( syz == "L"  ) grid[3][i] = 1;
            else if( syz == "M"  ) grid[4][i] = 1;
            else if( syz == "S"  ) grid[5][i] = 1;
            else if( syz == "XS"  ) grid[6][i] = 1;
        }
        source = 0;
        sink  = 7 + m;

        mf = 0;

        while(true) {
            f = 0;
            vector<int> d(_MAX_,inf);
            d [source] = 0;
            queue<int>q;
            //cout << " debug " << endl;
            q.push(source);
            parent.assign(_MAX_,-1);
            while( !q.empty() ) {
                //cout << " debug " << endl;
                int u = q.front();
                q.pop();
                if( u == sink ) break;
                for ( int v = 0; v < _MAX_; v++) {
                    if( grid[u][v] > 0 && d [v] == inf ) {
                        d[v] = d[u] + 1;
                        q.push(v);
                        parent[v] = u;
                    }
                }
            }
          //  debug;
            augment(sink,999999);
            if( f == 0) break;
            mf+=f;
        }
        if ( mf == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

