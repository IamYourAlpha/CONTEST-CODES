#include<stdio.h>
#include<set>
using namespace std;

multiset<int> mm;

int main() {
      int n,m;
      int demo;
      long long ans = 0;
      while(scanf("%d",&n)!=EOF) {
            ans=0;
            if(n==0) return 0;
            for(int j=0; j<n; j++) {
                  scanf("%d",&m);
                  for(int i=0; i<m; i++) {
                        scanf("%d",&demo);
                        mm.insert(demo);
                  }
                  ans  = ans + (*mm.rbegin()-*mm.begin());
                  mm.erase(mm.begin());
                  mm.erase( mm.find( *mm.rbegin() ) );
            }
            printf("%lld\n",ans);
            mm.clear();
      }
      return 0;
}
