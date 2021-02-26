#include<stdio.h>

int mp[1000];
int ans[1000];
int course;
int n;
int main() {

freopen("input.txt","r",stdin);
      for(int i=100; i<=500; i++) mp[i] = i-99;
      //  for(int i=100;i<120;i++) cout << mp[i] << endl;
      while(scanf("%d",&n)!=EOF) {
          int out =0;;
            for(int i=0;i<1000;i++) ans[i]=0;
            for(int i=0; i<n; i++) {
                  for(int ii=0; ii<5; ii++) {
                        scanf("%d",&course);
                        ans[i]  =ans[i]  + (mp[course]);
                  }
            }
            for(int i=0; i<n; i++) {
                  for(int j=0; j<n; j++) {
                        if(i!=j) {
                              if(ans[i]==ans[j])  out++;
                        }
                  }
            }
            printf("%d\n",out);
      }
      return 0;
}
