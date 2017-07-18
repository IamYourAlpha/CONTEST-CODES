#include<bits/stdc++.h>
using namespace std;


struct graph {
    int num,x,y,wt;
} ed[40000];

bool taken[40000];
int p[40000];
int rank_[40000];
int n,m;

void make_set(int node) {
    rank_[node] = 0;
    p[node] = node;
}


int find_(int x) {
    if( x != p[x] )
        p[x] = find_(p[x]);
    return p[x];
}


void union_(int x, int y) {
    if( rank_[x] > rank_[y] ) {
        p[y] = x;
    } else {
        p[x] = y;
        if( rank_[x] == rank_[y] )
            rank_[y]++;
    }
}


int main() {
    //freopen("input.txt","r",stdin);
    int tc;
    cin >> tc;
    while(tc--) {
        memset(taken,false,sizeof(taken));
        memset(p,-1,sizeof(p));
        memset(rank_,0,sizeof(rank_));


        for(int i=0; i<=40000; i++) make_set(i);
        cin >> n >> m;
        for(int i=1; i<=m; i++) {
            int a,b;
            cin >> a >> b;
            ed[i].num = i;
            ed[i].x = a;
            ed[i].y = b;
            union_(ed[i].x,ed[i].y);
        }
        for(int i=1; i<=n-1; i++) {
            int demo;
            cin >> demo;
            taken[demo] = true;
        }
        int c=0;
        set<int> st;
        for(int i=1; i<=m; i++)
            if(taken[ed[i].num]) {

                st.insert(ed[i].x);
                st.insert(ed[i].y);
            }
        if(st.size()==n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

