using namespace std;
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define ll  long long
ll n;
ll C;
ll C_;
ll ARR[4][4020];
ll SUM_A_B[4000*4000];
ll SUM_C_D[4000*4000];


void prep() {
    C=0;
    C_=0;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            SUM_A_B[C_]=ARR[0][i]+ARR[1][j];
            C_++;
        }
    }
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            SUM_C_D[C]= -1*( ARR[2][i]+ARR[3][j] );
            C++;
        }
    }
    // printf("%d\n",C);
}


ll b_s(ll l,ll r,ll key ) {
    // printf("here1\n");
    ll mid,ret=0,left;
    while(l<=r) {
        //printf("here3");
        mid=(l+r)/2;
        if(SUM_C_D[mid]==key) {
            left=mid-1;
            while(left>=0 && SUM_C_D[left]==key) {
                left--;
                ret++;
            }
            while(mid<C_ && SUM_C_D[mid]==key) {
                mid++;
                ret++;
            }
            return ret;
        }

        else if(SUM_C_D[mid]>key)
            r=mid-1;
        else l=mid+1;
    }
    return 0;
}

void input() {
    scanf("%lld",&n);
    for(ll i=0; i<n; i++) scanf("%lld %lld %lld %lld",&ARR[0][i],&ARR[1][i],&ARR[2][i],&ARR[3][i]);
}


ll calc() {
    // printf("here\n");
    // printf("%d\n",C_);
    ll ans=0;
    sort(SUM_A_B,SUM_A_B+C_);
    sort(SUM_C_D,SUM_C_D+C_);
    for(ll i=0; i<C_;) {
        ll byte=0;
        ll byte_=0;
        ll  demo=SUM_A_B[i];
        while(SUM_A_B[i]==demo && i<C_) {
            byte++;
            i++;
            //  printf("%d\n",byte);
        }
        byte_=b_s(0,C_,demo);
        //printf("%d\n",byte_);
        ans+=(byte*byte_);
    }
    return ans;
}


void init() {
    for(ll i=0; i<4; i++)
        for(ll j=0; j<4020; j++) ARR[i][j]=0;
    for(ll i=0; i<4000*4000; i++) {
        SUM_A_B[i]=0;
        SUM_C_D[i]=0;
    }
}

int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        ll aans;
        init();
        input();
        prep();
        aans=calc();
        printf("%lld\n\n",aans);
    }
    return 0;
}
