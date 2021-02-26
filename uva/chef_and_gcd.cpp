#include<stdio.h>
#define max_(a,b) (long long)a > (long long)b ? a : b
typedef long long ll;

struct ss {
      int u;
      int v;
} node;

ll a[100000];

bool marked[100000];
int n,q;
int L,R,temp;
int nodeu,nodev;

inline ll gcd(ll a,ll b) {
      if(a==0) return b;
      else return gcd(b%a,a);
}


void mark(int L,int R) {
     n = temp;
   // printf("n : : %d\n",n);
      for(int i= L; i<=R; i++) {
            marked[i]=true;
      }
      return ;
}


void reset() {
     n = temp;
  //  printf("n : : %d\n",n);
      for(int i=1; i<=100000; i++) marked[i]=false;
      return ;
}

void check(int L,int R) {
     // printf("L %d, R  %d ",L,R);
         n = temp;
      int demo = (R-L)+1;
        nodev = n-demo;
   // printf("n : : %d\n",n);
    // printf("n-demo, n  : %d %d\n",n-demo,n);
      if( (n-demo)==1) {
            for(int i=1; i<=n; i++)
                  if(!marked[i]) nodeu=i;
            //  return node;
      }
      return ;
}

int main() {
      freopen("input.txt","r",stdin);

      int tc;
      ll ans;
      scanf("%d",&tc);
      while(tc--) {
            scanf("%d %d",&n,&q);
            temp = n;
            for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
            for(int i=1; i<=q; i++) {
                   // n=temp;
                  int L,R;
                  ans = -1e8;
                  scanf("%d %d",&L,&R);
                  reset();
                  mark(L,R);
                  for(int k=1; k<=n; k++) {
                        // printf("OK\n");
                        for(int ii=1; ii<=n; ii++) {
                              //  printf("OK\n");
                              if(marked[ii]) ii++;
                              for(int jj=1; jj<=n; jj++) {
                                    if(!marked[ii] && !marked[jj] && ii<jj) {
                                          ans = max_(ans,gcd(a[ii],a[jj]));
                                          marked[ii]=true;
                                          //  printf("%lld %lld\n",a[ii],a[jj]);
                                    }
                              }
                        }
                  }
                  reset();
                  mark(L,R);
                  check(L,R);
               //   printf("node val : %d %d\n",nodeu,nodev);
                  if(nodev==1)
                        printf("%lld\n",a[nodeu]);
                  else
                        printf("%lld\n",ans);
                  // ese  printf("");
                  ans = -1e8;
            n=temp;
            }
      }
      return 0;
}
