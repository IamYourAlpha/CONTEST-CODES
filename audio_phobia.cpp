#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int city[1000+7][1000+7];
int c,s,q;

void floyd_warshall() {
    for(int k=1; k<=c; k++) {
        for(int i=1; i<=c; i++) {
            for(int j=1; j<=c; j++) {
                // if(city[i][j]!=2147483647 && city[i][k]!=2147483647 && city[k][j]!=2147483647)
                city[i][j]=min( city[i][j],max(city[i][k],city[k][j]) );
            }
        }
    }
}

int main() {
    int u,v,w;
    int tc=1;
    int max_=2147483647;
    bool ok=false;
    while(scanf("%d %d %d",&c,&s,&q)!=EOF) {
        for(int i=0; i<=1000; i++)
            for(int j=0; j<=1000; j++) city[i][j]=2147483647;
        if(c==0 && s==0 && q==0) return 0;
        if(ok) printf("\n");
        ok=true;
        for(int i=0; i<s; i++) {
            scanf("%d %d %d",&u,&v,&w);
            city[u][v]=w;
            city[v][u]=w;
            // max_=max(max_,w);
        }
        floyd_warshall();
        int s,d;
        printf("Case #%d\n",tc);
        for(int i=0; i<q; i++) {
            scanf("%d %d",&s,&d);
            if(city[s][d]==max_) printf("no path\n");
            else    printf("%d\n",city[s][d]);
        }
        tc++;
        //    max_=-2147483647;
    }
    return 0;
}
