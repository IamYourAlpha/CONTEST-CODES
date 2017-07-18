#include<bits/stdc++.h>
#define MAX 214748364
using namespace std;
int main() {

      int arr[1000+666];
      bool visited[1000+666];
      int dif,n;
      int ans=-1;
      scanf("%d",&n);
      for(int i=0; i<n; i++) {
            scanf("%d",&arr[i]);
      }
      int c=1;
      int final_ans=MAX;
      memset(visited,false,sizeof(visited));

      for(int kk=0; kk<n; kk++) {
            visited[arr[c-1]]=false;
            visited[arr[c]]=true;
            ans=-1;
            for(int ii=0; ii<n; ii++) {
                  for(int jj=0; jj<n; jj++) {
                        if(!visited[ arr[ii] ] && !visited[ arr[jj] ] && ii<jj) {
                              dif = arr[jj]-arr[ii];
                              ans = max(ans,dif);
                              ii++;
                              if(ii==c) ii++;
                        }
                  }
            }
            final_ans=min(ans,final_ans);
            c++;
            if(c==n-1) break;
      }
      printf("%d\n",final_ans);
      return 0;
}
