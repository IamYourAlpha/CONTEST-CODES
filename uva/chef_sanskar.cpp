using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define max_(a,b)  a>b ? a:b

ll make,n,k;
ll memo[21][10*10*10*10*10*10];
ll arr[100];

ll dp(ll index,ll amount) {
     if(index>=n) {
          if(amount==make) return 1;
          else return 0;
     }
     if(memo[index][amount]!=-1) return memo[index][amount];
     ll ret1=0;
     ll ret2=0;
     if(arr[index]+amount<=make)   ret1= dp(index+1,amount+arr[index]);
     ret2= dp(index+1,arr[index]);
     return  memo[index][amount]= ret1+ret2;
}


int main() {
     int tc;
     ll tot;
     scanf("%d",&tc);
     while(tc--) {
            tot=0;
          scanf("%lld %lld",&n,&k);
          for(int i=0; i<n; i++) {
               scanf("%lld",&arr[i]);
               tot+=arr[i];
          }
          if(tot<k || (tot%k)!=0) printf("no\n");
          else {
               make=tot/k;
               memset(memo,-1,sizeof(memo));
               ll ans = dp(0,0);
                //printf("%d",ans);
                ans=ans>>1;
               for(int i=0;i<10;i++)
                 for(int j=0;j<20;j++) printf("%lld\n",memo[i][j]);
               if(ans==k) printf("yes\n");
               else printf("no\n");
          }
     }
     return 0;
}
