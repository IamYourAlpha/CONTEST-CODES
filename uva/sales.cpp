#include<bits/stdc++.h>
using namespace std;

int main() {
   // freopen("input.txt","r",stdin);
      int tc;
      int a[1000+66];
      int b[1000+66];
      int ans;
      cin >> tc;
      while(tc--) {
            ans = 0;
            int k=0;
            int n;
            cin >>n;
            int demo;
            for(int i=0; i<n; i++) cin >> a[i];
            for(int i=1; i<n; i++) {
                  int demo = a[i];
                  for(int j=0; j<i; j++) {
                        if(a[j]<=demo) ans++;
                  }
                  b[k++]=ans;
                  ans=0;
            }
            ans = 0;
      for(int i=0;i<k;i++) {  ans = ans + b[i];}
      cout << ans << endl;
      k=0;
      for(int i=0;i<1000+66;i++) {b[i]=0; a[i]=0;}
      }
      return 0;
}
