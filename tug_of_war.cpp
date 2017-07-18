/*author: MD INTISAR  CHOWDHURY
Uhunt : in2
Institute: Ahasanullah University of Science and Technology
*/

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

bool prime[1000000+2];
void seive(){
mem(prime,true);
prime[0]=prime[1]=false;
prime[2]=true;
for(long long i=4;i<1000000;i+=2) prime[i]=false;
  for(long long i=3;i*i<1000000;i++){
    if(prime[i])
        for(long long j=i+i;j<1000000;j+=i)
            prime[j]=false;

}
//repo(i,10)  if(!prime[i]) cout<<i<<endl;
}

int main(){
    long long  n;
    seive();
    while(cin>>n){
    for(long long  i=3;i<1000000;i++){
       if(!prime[i]  && !prime[abs(n-i)]){
             cout<<i<<" "<<abs(n-i)<<endl;
             break;
          }
    }
    }
    return 0;
}
