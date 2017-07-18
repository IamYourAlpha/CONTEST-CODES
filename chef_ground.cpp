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
int in[100];
int n,m;
 bool check[1000];
int find_max() {
    int max=-999;
    for(int i=0; i<n; i++)
        if(in[i]>max ) max=in[i];
    return max;
}
void incr_max(int max) {
    int max_index;
    for(int i=0; i<n; i++) if(in[i]>max) max_index=i;
    ++in[max_index];
}

int super_sonic() {
    int ret=0;

    int sonic;
    sonic= find_max();
    cout<<"highest :"<<sonic<<endl;
        if(check[sonic]==false) in[sonic]++;
    for(int i=0; i<n; i++) {
        if(check[sonic]==true)
            ret+=sonic-in[i];
    }
    check[sonic]=false;
    return ret;
}

int main() {
    int t_c;
    int ans;
    scanf("%d",&t_c);
    for(int i=1; i<=t_c; i++) {
        memset(check,true,sizeof(check));
        scanf("%d%d",&n,&m);
        for(int j=0; j<n; j++) scanf("%d",&in[j]);
        while(ans!=m) {
            ans=0;
            ans=super_sonic();
            if(ans>m) break;
        }
        // debug
        cout<<ans<<endl;
        for(int k=0;k<n;k++) cout<<ans-in[k]<<endl;
        (ans==m)?  printf("yes\n") : printf("no\n");
    }
    return 0;
}

