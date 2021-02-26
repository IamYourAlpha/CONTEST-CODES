#include<bits/stdc++.h>
using namespace std;
bool seen[10000];
string str[1000];

int main() {
      int n,m;
      int ans =0;
      scanf("%d %d",&n,&m);
      for(int i=0; i<n; i++)  cin>>str[i];
      seen[0]=true;
      int flag=0;
      for(int i=0; i<m; i++) {
            flag = 0;
            for(int j=0; j<n-1; j++) {
                  if(!seen[j+1])
                        if(str[j][i]>str[j+1][i]) {
                              flag=1;
                              break;
                        }
            }
            if(flag) ans++;
            else {
                  for(int j=0; j<n-1; j++) {
                        if(str[j][i]<str[j+1][i] && !seen[j+1]) {
                              seen[j+1]=true;
                        }
                  }
            }
      }
      cout<<ans<<endl;
      return 0;
}
