#include<bits/stdc++.h>
#define MAX 10000000
#define ll long long

bool prime[100000000];

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


int main(){
    seive();
    int n;
    int c=0;
    scanf("%d",&n);
    for(int i=2;;i++){

            if(prime[i]){ printf("%d ",i); c++; if(c==n) break;}
    }
    return 0;
    }
