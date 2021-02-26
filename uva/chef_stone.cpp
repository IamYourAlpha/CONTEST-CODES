#include<stdio.h>
#define max_(a,b) (long long)a > (long long)b ? a : b
typedef long long ll;

ll a[100000];
int main(){
    int tc;
    ll n,k;
    scanf("%d",&tc);
    while(tc--){
            ll demo;
            ll ans = -1e8;
            scanf("%lld %lld",&n,&k);
            for(int i=0;i<n;i++){ scanf("%lld",&demo); a[i]=(k/demo);}
            for(int i=0;i<n;i++){ scanf("%lld",&demo); ans = max_(ans,demo*a[i]);}
            printf("%lld\n",ans);
    }
    return 0;
}
