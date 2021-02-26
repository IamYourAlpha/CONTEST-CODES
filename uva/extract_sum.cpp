using namespace std;
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int A[10000+10];
int n;

int main() {
    int make;
    int f_a,f_b,a,b,temp;
    int ans=1<<30;
    int dif;
    while( scanf("%d",&n)!=EOF) {
        ans=1<<30;
        dif=1<<30;
        f_a=0;
        a=0;
        b=0;
        f_b=0;
        for(int i=0; i<n; i++)
            scanf("%d",&A[i]);
        scanf("%d",&make);
        sort(A,A+n);

        //    for(int i=0; i<n; i++) printf(" %d ",A[i]);
        for(int i=n-1; i>=0; i--) {
            if(A[i]<make) {
                if(binary_search(A,A+n,make-A[i])) {
                    a=make-A[i];
                    b=A[i];
                    dif= abs(b-a);
                    //   printf(" %d %d\n",a,b);
                }
                if(dif<ans) {
                    ans=dif;
                    f_a=a;
                    f_b=b;
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n",f_a,f_b);
        printf("\n");
    }
    return 0;
}
