#include<stdio.h>
#include<string.h>
#define max_(a,b) (int)a  >  (int)b ? a : b
#include<iostream>
#include<algorithm>
using namespace std;

int arr[2000+10];
int lis[2000+10];
int lisr[2000+10];
int n;

int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        memset(lis,0,sizeof(lis));
        for(int i=0; i<n; i++) lis[i]= 1;

        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if(arr[i]>arr[j] && lis[ j ] + 1 > lis[ i  ] )
                    lis[i] = lis[j] + 1;
            }
        }
        memset(lisr,0,sizeof(lisr));
        for(int i=0; i<n; i++) lisr[i]= 1;

        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if(arr[i]<arr[j] && lisr[ j ] + 1 > lisr[ i  ] )
                    lisr[i] = lisr[j] + 1;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++)  ans = max(ans,(lisr[i]+lis[i])-1);
         //  cout  << lis[i] << " : " << lisr[i]<<endl;
           printf("%d\n",ans);
    }
    return 0;
}
