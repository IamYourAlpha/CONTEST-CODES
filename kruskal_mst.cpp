#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;

vector<pii> A;
long long p[100000], rank_[100000];
long long nE, nV;

struct graph {
    long long u, v, c;
} edges[100000];

void make_set(int x) {
    p[x] = x;
    rank_[x] = 0;
}


long long find_set(int x) {
    if( x != p[x] )
        p[x] = find_set(p[x]);
    return p[x];
}

void link(int x, int y) {
    if( rank_[x] > rank_[y] ) {
        p[y] = x;
    } else {
        p[x] = y;
        if( rank_[x] == rank_[y] )
            rank_[y]++;
    }
}

void Union(int x, int y) {
    link(find_set(x), find_set(y));
}


bool comp( graph a, graph b ) {
    return a.c<b.c;
}


long long MSTKruskal() {
    int i;
    long long ret=1;
    pii node;
    for(i=0; i<nV; i++)
        make_set(i);
    sort(edges, edges+nE, comp);
    for(i=0; i<nE; i++) {
        node.first = edges[i].u;
        node.second= edges[i].v;
        if( find_set(node.first) != find_set(node.second) ) {
            A.push_back(node);
            ret *= edges[i].c %(1000000000+7);
            Union(node.first, node.second);
        }
    }
    return ret %(1000000000+7);
}


int main() {
   // freopen("input.txt","r",stdin);
    int tc;
    cin >> tc;
    while(tc--) {
        //memset(rank_,0,sizeof(rank_));
        //memset(p,-1,sizeof(p));
        int i;
        scanf("%lld%lld", &nV, &nE);
        for(i=0; i<nE; i++) {
            scanf("%lld%lld%lld", &edges[i].u, &edges[i].v, &edges[i].c);
        }
        printf("%lld\n", MSTKruskal());
    }
    return 0;
}
