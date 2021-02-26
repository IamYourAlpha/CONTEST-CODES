#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
#define ll long long
bool prime[MAX];
int c[MAX];
int c1[MAX];
int n,k;
void seive() {
      memset(prime,true,sizeof(prime));
      prime[0]=false;
      prime[1]=false;
      prime[2]=true;

      for(int i=4; i<MAX; i+=2) prime[i]=false;
      for(int i=3; i*i<MAX; i++) {
            if(prime[i]) {
                  for(int k=i+i; k<MAX; k+=i) prime[k]=false;
            }
      }
//                for(int i=0; i<20; i++) if(prime[i]) printf("%d\n",i);
}


int main() {
      seive();
 freopen("input.txt","r",stdin);
      while(scanf("%d %d",&n,&k)!=EOF) {
          int  memo = k;
          int  memo2 = n;
            for(int i=2; i<=n; i++) {
                  int demo = i;
                  for(int k=2; k*k<=MAX; k++) {
                        if(prime[k]) {
                              while(demo>1 && demo%k==0) {
                                    demo=demo/k;
                                    c[k]++;
                              }
                        }
                  }
            }
            for(int i=2; i*i<=MAX; i++) {
                  if(prime[i]) {
                        while(k>1 && k%i==0) {
                              k=k/i;
                              c1[i]++;
                        }
                  }
            }

            bool flag=true;
            for(int i=2; i*i<=MAX; i++) {
                  if(c1[i]>c[i]) {
                        flag=false;
                        break;
                  }
            }
            if(flag) printf("%d divides %d!\n",memo,memo2);
            else printf("%d does not divide %d!\n",memo,memo2);
            memset(c,0,sizeof(c));
            memset(c1,0,sizeof(c));

      }
      return 0;
}
