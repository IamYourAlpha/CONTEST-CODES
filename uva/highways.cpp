using namespace std;
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<vector>
double w[1000][1000];
double x[1000],y[1000];
int parent[1000];
int rank_[1000];
vector< pair<int,int> >viii;

void init() {
    for(int i=0; i<=1000; i++) {
        parent[i]=i;
        rank_[i]=0;
    }
}
struct Edge {
    int u,v;
    double val;
} a[1000*1000];


double calc(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}



bool comp(Edge x,Edge y) {
    if(x.val<y.val) return true;
    return false;
}

int find_(int x) {
    if(parent[x]==x) return x;
    else return parent[x]= find_(parent[x]);
}


bool UNION_(int x,int y) {
    int a;
    int b;
    a=find_(x);
    b=find_(y);
    if(a==b) return false;
    if(rank_[a]>rank_[b]) {
        parent[b]=a;
    } else {
        if(rank_[a]==rank_[b])
            rank_[b]++;
        parent[a]=b;
    }
    return true;
}

int main() {
    int tc;
    bool ok=false;
    int n,m;
    scanf("%d",&tc);
    while(tc--) {
        if(ok) printf("\n");
    ok=true;
        ok=true;
        init();
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%lf %lf",&x[i],&y[i]);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i!=j)
                    w[i][j]= calc(x[i],y[i],x[j],y[j]);
                // printf("%lf",w[i][j]);
            }
        }
        scanf("%d",&m);
        int u,v;
        for(int i=0; i<m; i++) {
            scanf("%d %d",&u,&v);
            w[u][v]=0;
            w[v][u]=0;
        }
        int pos=0;
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                a[pos].u=i;
                a[pos].v=j;
                a[pos++].val=w[i][j];

            }
        }
        double ans=0;
        sort(a,a+pos,comp);
        for(int i=0; i<pos; i++)
            if( UNION_(a[i].u,a[i].v) && a[i].val!=0 )
                viii.push_back(make_pair(a[i].u,a[i].v));

        if(viii.size()==0) printf("No new highways need.\n");
        else {
//       sort(viii,viii+viii.size());
            for(int i=0; i<viii.size(); i++) printf("%d %d\n",viii[i].first,viii[i].second);
        }
        viii.clear();
    }
    return 0;
}
