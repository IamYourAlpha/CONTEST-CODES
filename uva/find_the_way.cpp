#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    int k;
    while(scanf("%d %d",&n,&k)==2) {
        double c = 0;
        if( (n-k)>k ) {
            for(ll i = (n-k+1) ; i<=n; i++) {
                c +=  (log10(i) - log10(n-i+1));
            }
        } else {
            for(ll i = k+1  ; i<=n; i++) {
                c += ( log10(i) - log10(n-i+1));
            }
        }
        printf("%.lf\n",floor(c)+1);
        c = 0;
    }

    return 0;
}
