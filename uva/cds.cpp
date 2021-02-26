#include<bits/stdc++.h>
using namespace std;


int main() {
      set<int>si;
      int n,m;
      int demo;
      while(scanf("%d %d",&n,&m)==2) {
            if(n==0 && m==0 )  return 0;
            for(int i=0; i<n; i++) { scanf("%d",&demo); si.insert(demo);}
            for(int i=0; i<m; i++) {
                  scanf("%d",&demo);
                        si.insert(demo);
                  }
            printf("%d\n",(n+m)-si.size());
            si.clear();
      }
      return 0;
}
