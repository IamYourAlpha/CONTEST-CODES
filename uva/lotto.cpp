#include<stdio.h>

int main() {
      freopen("take.txt","r",stdin);
      int arr[100];
      int num;
      bool ok = false;
      while(scanf("%d",&num)==1) {
            if(num==0) return 0;
            for(int i=0; i<num; i++) scanf("%d",&arr[i]);
            if(ok) printf("\n");
            ok = true;

            for(int i=0; i<num; i++) {
                  for(int j=i+1; j<num; j++) {
                        for(int k=j+1; k<num; k++) {
                              for(int l=k+1; l<num; l++) {
                                    for(int m=l+1; m<num; m++) {
                                          for(int n=m+1; n<num; n++) {
                                                printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k],arr[l],arr[m],arr[n]);
                                          }
                                    }
                              }
                        }
                  }
            }
      }
      return 0;
}

