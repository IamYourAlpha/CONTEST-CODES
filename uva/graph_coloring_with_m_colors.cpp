#include <bits/stdc++.h>



/****************** templates***********************/



int arr[1000];

int main() {

    int n;
    int c=0;
    while(scanf("%d",&n)==1) {
        if(n==0) return 0;
        int tot=0;
        for(int i=0; i<n; i++) {
            scanf("%d",&arr[i]);
            tot+=arr[i];
        }
        int avg= tot/n;
    int ans=0;
        sort(arr,arr+n);
        for(int i=n-1; i>=0; i--) {
            if(  arr[i]-avg>=0 ) ans+=arr[i]-avg;
        }
        printf("Set #%d\n",++c);
        printf("The minimum number of moves is %d.\n\n",ans);
    }
    return 0;
}




