using namespace std;
#include <bits/stdc++.h>
#define MAX_ 1000000
typedef vector <int> vi;
vector<vi> grid;
int n,m,s,v;
double gox[MAX_],goy[MAX_];
double holex[MAX_],holey[MAX_];
int match[MAX_];
int seen[MAX_];


double d (int i,int j) {
    double x = ( gox[i] - holex[j] ) * ( gox[i] - holex[j] );
    double y = ( goy[i] - holey[j] ) * ( goy[i] - holey[j] );
    return sqrt ( x + y);
}

int BPM(int gob) {
    if( seen [ gob ] ) return 0;
    seen [ gob ] = 1;
    for(int i =0; i<grid[gob].size(); i++) {
        if(match[ grid[gob][i] ] == -1 || BPM(match[ grid[gob][i] ]) ) {
            match[ grid[gob][i] ] = gob;
            return 1;
        }
    }
    return 0;
}

int main() {
     freopen("in.txt","r",stdin);
    while( scanf("%d %d %d %d",&n,&m,&s,&v)!=EOF ) {
        for ( int i=0; i<n; i++ ) scanf("%lf %lf",&gox[i],&goy[i]);
        for ( int i=0; i<m; i++ ) scanf("%lf %lf",&holex[i],&holey[i]);
        int sink = n;
        int tank = n + m;
        grid.assign(tank, vi());
        for(int i=0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if( ( d(i,j)/(double)v ) < s )
                    grid[i].push_back(j+n);
            }
        }
        int mf = 0;
        memset(match,-1,sizeof(match));
        for(int i=0; i<n; i++) {
            memset(seen,0,sizeof(seen));
            if(BPM(i)) mf++;
        }
        cout << n - mf << endl;
    }
}
