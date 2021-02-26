
//headers
using namespace std;
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
#include<math.h>
#include<queue>
#include<cstdlib>
#include<ctype.h>
#include<string>
#include<cstdio>
#include<algorithm>

/**********INPUT******/
#define sint(a)     scanf("%d",&a)
#define pint(a)     printf("%d",a)
//#define sintll(a)   scanf("%lld",&a)
//#define pintll(a)   printf("%lld",a)
//#define sint2(a,b)  scanf("%d%d",&a,&b)


#define MAX(a,b) (a > b) ? (a) : (b)
#define MIN(a,b) (a < b) ? (a) : (b)
#define MIN3(a,b,c) (a < b) ? (a < c ? a : c) : (b < c ? b : c)
#define MAX3(a,b,c) (a > b) ? (a > c ? a : c) : (b > c ? b : c)
#define mem(x,y) memset(x,y,sizeof(x));
#define pb push_back
#define pf pop_front()
#define N 1000000+7


/* loops****/
#define rep(a,n) for(int a=1;a<=n;a++)
#define repo(a,n) for(int a=0;a<n;a++)

#define PINF 2147483647
#define NINF -2147483647
#define Pi acos(-1.0)

typedef priority_queue< int,vector<int>,greater<int> > my_q;


/****************** templates***********************/

bool prime[100000000];
void seive() {


    mem(prime,true);
    prime[0]=prime[1]=false;
    prime[2]=true;
    for(long long i=4; i<=100000000; i+=2) prime[i]=false;
    for(long long i=3; i*i<=100000000; i++) {
        if(prime[i])
            for(long long j=i+i; j<=100000000; j+=i)
                prime[j]=false;

    }
//repo(i,10)  if(!prime[i]) cout<<i<<endl;
}

int main() {
    long long  n;
    seive();
    while(cin>>n) {


        if(n&1) {

            if(prime[n-2]) {
                printf("%lld is the sum of 2 and %lld.\n",n,n-2);
            } else printf("%lld is not the sum of two primes!\n",n);
        }



        else {
            bool flag=false;
            prime[0]=false;
            int m=0;


            for(long long  i=2; i<=n; i++) {
                if( prime[ i ]  && prime[n-i] && (n-i)!=i  ) {
                    printf("%lld is the sum of %lld and %lld.\n",n,i,n-i);
                    flag=true;
                    break;
                }
                m++;
            }


            if(!flag) printf("%lld is not the sum of two primes!\n",n);
        }

    }
    return 0;
}
