using namespace std;
#include<bits/stdc++.h>

int ncom;
int x[100];
int y[100];
int confiq[100];
int ansfig[100];
int net;
int n;
int main() {
  freopen("in.txt","r",stdin);

    while(scanf("%d",&n)!=EOF) {
     if(n==0) return 0;
        for(int i=0; i<n; i++) {
            scanf("%d %d",&x[i],&y[i]);
            confiq[i] = i;
        }
        double sum = 0xfffffff;
        do {
            double tot = 0.00;
            for(int i=1; i<n; i++) {
                double dist = sqrt( ((x[confiq[i]]-x[confiq[i-1]])*(x[confiq[i]]-x[confiq[i-1]]))+ ((y[confiq[i]]-y[confiq[i-1]])*(y[confiq[i]]-y[confiq[i-1]])) )  + 16;
                tot+=dist;
            }
            if(sum > tot) {
                sum = tot;
                for(int i=0; i<n; i++) ansfig[i] = confiq[i];
            }
        } while(next_permutation(confiq,confiq+n));
        printf("**********************************************************\n");
        printf("Network #%d\n",++net);
        for(int i=1; i<n; i++) {
        double dist = sqrt( ((x[ansfig[i]]-x[ansfig[i-1]])*(x[ansfig[i]]-x[ansfig[i-1]]))+ ((y[ansfig[i]]-y[ansfig[i-1]])*(y[ansfig[i]]-y[ansfig[i-1]])) ) + 16;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",x[ansfig[i-1]],y[ansfig[i-1]],x[ansfig[i]],y[ansfig[i]],dist);
        }
        printf("Number of feet of cable required is %.2lf.\n",sum);
      //  printf("**********************************************************\n");
    }
    return 0;
}



