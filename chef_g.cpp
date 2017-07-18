
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
using namespace std;

long long in[100000+7];
long long n,m;
long long find_max() {
    long long maxi=-9999;
    for(int i =0; i<n; i++)
        if(in[i]>=maxi) maxi= in[i];
    return maxi;
}

bool all_equal() {
    int c=0;
    for(int i=0; i<n-1; i++) if(in[i]==in[i+1]) c++;
    if(c==n-1) return true;
    else return false;
}
int main() {

    int t_c;
    long long max;
    long long ans;
    scanf("%d",&t_c);
    while(t_c--) {
        scanf("%lld%lld",&n,&m);
        for(int i=0; i<n; i++) scanf("%lld",&in[i]);
        if(all_equal()==true && (m%n==0)) {printf("Yes\n"); continue;}
        else{
               max=find_max();
        for(int i=0; i<n; i++) {
            if(in[i]<=max){ m-=(max-in[i]);
            in[i]+=(max-in[i]);
            cout<<m<<endl;
            }
        }
        if(m==0 && all_equal()) printf("Yes\n");
        else printf("No\n");
        }
    }
    return 0;
}
