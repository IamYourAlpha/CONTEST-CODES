#include<bits/stdc++.h>
using namespace std;

int main() {
      // freopen("input.txt","r",stdin);
      int in[1000+666];
      int dif;
      int n,m;
      int ans,k =0;
      while(scanf("%d",&n)!=EOF) {
            if(n==0) return 0;
            for(int i=0; i<n; i++) scanf("%d",&in[i]);
            printf("Case %d:\n",++k);
            scanf("%d",&m);
            for(int i=0; i<m; i++) {
                  int make;
                  scanf("%d",&make);
                  int max_dif = INT_MAX;
                  for(int ii=0; ii<n; ii++) {
                        for(int kk=0; kk<n; kk++) {
                              if(ii!=kk) {
                                    dif = abs( (in[ii]+in[kk])-make );
                                    if(dif<max_dif) {
                                          max_dif = dif;
                                          ans = in[ii]+in[kk];
                                    }
                              }
                        }
                  }
                  printf("Closest sum to %d is %d.\n",make,ans);
            }
      }
      return 0;
}
