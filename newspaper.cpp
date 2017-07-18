#include<bits/stdc++.h>
using namespace std;

map <char,int> mp;

void reset() {
      for(int i=0; i<=128; i++) {
            mp[i] = 0;
            //    printf("%c %d\n",i,mp[i]);
      }
      return ;
}
int main() {
      //freopen("input.txt","r",stdin);
      char str[100000];
      int demo;
      int nn;
      int n;
      char ch,cc;
      int tc;
      scanf("%d",&tc);
      while(tc--) {
            int ans = 0;
            reset();
            scanf("%d %c",&n,&cc);
            for(int i=0; i<n; i++) {
                  scanf("%c %d %c",&ch,&demo,&cc);
                  // cout << ch << demo << endl;
                  mp[ch] = demo;
            }
            scanf("%d %c",&nn,&cc);
            while(nn--) {
                  gets(str);
                  for(int j=0; j<strlen(str); j++) {
                        ans +=  (mp[str[j]]);
                        // printf(" %d  \n",mp[str[j]]);
                  }
            }
            printf("%.2lf\n",(double)ans/100);
            ans = 0;
      }
      return 0;
}


