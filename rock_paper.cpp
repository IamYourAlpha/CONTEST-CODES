using namespace std;
#include<bits/stdc++.h>
#define MAX 1000000
int p1,p2;
string str1,str2;
double stat[MAX];
int lose[MAX];
int win[MAX];
int n,k;
int len;
int main() {
bool ok = false;

      while(scanf("%d",&n)!=EOF) {
            if(n==0) return 0;
            scanf("%d",&k);
      if(ok) printf("\n");
       ok=true;
            len= n* (n-1)/2;
            len =len *k;
            for(int i=0; i<len; i++) {
                  cin>>p1>>str1>>p2>>str2;
                  if(str1=="scissors" && str2=="paper") {
                        win[p1]++;
                        lose[p2]++;
                  }
                  if(str2=="scissors" && str1=="paper") {
                        win[p2]++;
                        lose[p1]++;
                       // lose[p2]++;
                  }
                  if(str1=="rock" && str2=="paper") {
                        win[p2]++;
                        lose[p1]++;
                       // lose[p2]++;
                  }
                  if(str2=="rock" && str1=="paper") {
                        win[p1]++;
                       // lose[p1]++;
                        lose[p2]++;
                  }
                  if(str1=="rock" && str2=="scissors") {
                        win[p1]++;
                       // lose[p1]++;
                        lose[p2]++;
                  }
                  if(str2=="rock" && str1=="scissors") {
                        win[p2]++;
                        lose[p1]++;
                       // lose[p2]++;
                  }
                 // else {win[p1]++; win[p2]++;}
                  stat[p1]=(double)win[p1]/((double)(lose[p1])+(double)win[p1]);
                  stat[p2]=(double)win[p2]/((double)(lose[p2])+(double)win[p2]);

            }
            for(int i=1;i<=n;i++){ if(((double)(lose[i])+(double)win[i])>0){ printf("%.3lf\n",stat[i]);} else printf("-\n");}
            memset(win,0,sizeof(win));
            memset(stat,0,sizeof(stat));
            memset(lose,0,sizeof(lose));
      }

      return 0;
}
