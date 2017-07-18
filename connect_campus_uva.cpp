using namespace std;
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define N 760

double w[N][N];
double x[N],y[N];
int parent[N*N],rank_[N*N];

int n,m;
struct Edge {
    int u,v;
    double val;
} a[N*N];


bool comp(Edge x,Edge y) {
    if(x.val<y.val) return true;
    return false;
}

double getDist(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


void init() {
    for(int i=0; i<=n*n; i++) rank_[i]=0, parent[i]=i;
}

int find_(int x) {
    if(parent[x]==x) return x;
    else return parent[x]= find_(parent[x]);
}



bool Union(int x,int y) {
    int a;
    int b;
    a=find_(x);
    b=find_(y);
    if(a==b) return false;
    if(rank_[a]>rank_[b]) {
        parent[b]=a;
    } else {
        if(rank_[a]==rank_[b])
            ++rank_[b];
        parent[a]=b;
    }
    return true;
}



int main() {
freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF) {
        memset(w,0,sizeof(w));
        for(int i=1; i<=n; i++) scanf("%lf %lf",&x[i],&y[i]);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i!=j)
                    w[i][j]= getDist(x[i],y[i],x[j],y[j]);
            }
        }
        int s,s1;
        scanf("%d",&m);
        for(int i=1; i<=m; i++) {
            scanf("%d %d",&s,&s1);
            w[s][s1]=0;
            w[s1][s]=0;
        }
        int  pos=0;
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                a[pos].u=i;
                a[pos].v=j;
                a[pos++].val=w[i][j];

            }
        }

        init();
        sort(a,a+pos,comp);
        double ans=0;
        for(int i=0; i<pos; i++) {
            if(Union(a[i].u,a[i].v))
               printf("%d %d\n",a[i].u,a[i].v);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
