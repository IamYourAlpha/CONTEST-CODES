

using namespace std;
#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
// Input macros

#define fun_(a,x)  a-x*(a/x)



int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long x=a-b;
    long long ans=0;
    if(a==b){ printf("infinity\n"); return 0;}
    if(x<0){ printf("0"); return 0;}
    else{
            for(long long  i=1;i*i<=x;i++){
                    if( x%i==0){
                          long long  dv= x/i;
                            if(i>b) ans++;
                            if(dv!=i && dv>b) ans++;
                    }
            }
            //if(ans==0){ printf("0"); return 0;}
            printf("%lld",ans); return 0;
    }
}
