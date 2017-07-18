#include<bits/stdc++.h>

using namespace std;


int arr[100000+100];

int main() {
     int tc;
     int len;
     scanf("%d",&tc);
     while(tc--) {

          scanf("%d",&len);
          for(int i=0; i<len; i++) scanf("%d",&arr[i]);
          sort(arr,arr+len);
          int ans=0;
          for(int i=len-1; i>0; i--) {
               if(arr[i]-arr[i-1]>0) ans++;
          }
          printf("%d\n",ans+1);
     }
     return 0;
}
