using namespace std;
#include<bits/stdc++.h>

//#define R(FileName) freopen("FileName","r",stdin)

typedef vector <int> vi;

int mst;
int v,e;
vi sec;
int p[1000];
int r[1000];
bool taken [1000];
struct Edge {
    int start;
    int end_;
    int w;
}edges[1000];

bool comp(Edge aa,Edge bb) {

    if(aa.w<bb.w) return true;
    else return false;
}

int FindParent(int node) {
    if( p [ node ] == node )  return node;
    else return   FindParent( p [ node ] );
}

void U(int u ,int v) {
    if( r [ u ] > r [ v ] )  p [ v ] = u;
    else {
        p [ u ] = v;
        if( r[ u ] == r [ v ] ) r [ u ]++;
    }
}

void SecondBest(int off_edge) {
    int tot = 0;
    int s;
    int e;
    int took = 0;
    for(int i = 0; i< 500 ; i++)  p [i] = i;
    for(int i=0; i<e ; i++) {
        if( i != off_edge ) {
            s = FindParent( edges[i].start );
            e = FindParent( edges[i].end_ );
            if(s != e )
                tot += edges[i].w;
                U(s,e);
            took++;
        }
    }
    if(took == e-1) sec.push_back(tot);
    return;
}

int main() {
    freopen("input.txt","r",stdin);
    int tc;
    cin >> tc;
    while(tc--) {
        for(int i=0; i<500; i++) {
            r [ i ] = 0;
            p [ i ] = i;
        }
        memset(taken,false,sizeof(taken));
        cin >> v >> e;
        for(int i=0; i<e; i++)
            cin >> edges[i].start >> edges[i].end_ >> edges[i].w;

        cout << " ok " << endl;
        int s,e;
        mst = 0;
        sort(edges, edges+e, comp);
        for(int i=0 ; i<e; i++) {
            s = FindParent(edges [ i ].start);
            e = FindParent(edges [ i ].end_);
            mst += edges [ i ].w;
            U(s,e);
            taken [ i ] = true;
        }

        for(int i = 0; i<e ; i++) if ( taken [ i ] ) SecondBest( i );
        cout << mst <<  sec[0] << endl;
    }
    return 0;
}
