#include<stdio.h>

int n,m;
int arr[1000+100];

bool fun(int cap) {
                int cur=0;
                int tot=0;
                for(int i=0; i<n; i++) {
                                if(arr[i]>cap) return false;
                                if(cur+arr[i]>cap) {
                                                cur=0;
                                }
                                if(cur==0) tot++;
                                cur+=arr[i];
                                if(tot>m) return false;
                }
                return true;
}



int main() {
                int high;
                int low;
                while(scanf("%d %d",&n,&m)!=EOF ) {
                                high=1000000;
                                low=0;
                                for(int i=0; i<n; i++) scanf("%d",&arr[i]);

                                while(high-low>0) {
                                                if(fun(high)) {
                                                                high=low+(high-low)/2;
                                                } else {
                                                                low=high;
                                                                high=high+(high/2);
                                                }
                                }
                                printf("%d\n",high+1);
                }
                return 0;
}
