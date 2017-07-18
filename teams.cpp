/*** the muffins*****/

using namespace std;
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>
#define ll long long
inline ll powmod(ll x,ll n, ll _mod) {
    ll res=1;
    while(n) {
        if(n&1)res=(res*x)%_mod;
        x=(x*x)%_mod;
        n>>=1;
    }
    return res;
}

ll n;
int main(){
    int tc;
    int c=0;
    scanf("%d",&tc);
    while(tc--){
            scanf("%lld",&n);
            printf("Case #%d: %lld\n",++c,n*powmod(2,n-1,1000000007)%1000000007);
    }
    return 0;
}
