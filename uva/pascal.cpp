//keep things simple!!

#include <cstdio>
#include<math.h>
#define  LL long long

LL a[1000][1000];

/*void pascal() {
    a[1][1] = 1;
    a[1][0] = 1;

    for (int i = 2; i <= 100; i++) {
        a[i][0] = 1;
        a[0][i]=0;
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
}
*/
long long nCr(long long n,long long m) {
    long long res=1,i;
    if(n-m<m)
        m=n-m;
    for(i=1; i<=m; i++,n--) {
        res=res*n;
        res=res/i;
    }
    return res;
}




int main() {

    LL n,m;

    scanf("%lld %lld",&n,&m);
/*   long long min=0;

    if(n%m==0) {
        for(int i=0; i<m; i++) {
            min+=nCr(n/m,2);
            //printf("%d",team[i]);
        }
        printf("%lld ",min);
    }*/


        LL a= n%m;
        LL b= m-a;
        LL aa= ((n/m+1)*((n/m+1)-1))/2;
        LL bb=(((n/m))*(((n/m))-1))/2;
       printf("%lld ",a*aa+b*bb);

//         dp();
/*    } else if(n%m!=0) {
        //printf(d\n",team[i]);
        for(int i=0; i<=n%m+2; i++) {
            min+=nCr(((n/m)+1),2);
            //    printf("%lld\n",(n/m)+1);
        }
        if(n/m>1)
            min+=nCr(n/m,2);
        printf("%lld ",min);
    } */
// code starts for the max value
    //for(int i=0; i<m; i++) team[i]=0;

    printf("%lld\n",((m-n)*(m-n-1))/2);

    return 0;
}



