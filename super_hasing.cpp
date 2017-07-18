#include<bits/stdc++.h>
using namespace std;

int call(int n){
    int ret = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            if(__gcd(i,j)!=1)ret++;
        }
    }
    return ret;
}

int main(){
    int t;
    cin >> t;
    for(int cs = 1;cs<=t;cs++){
        int n;
        cin >> n;
        printf("Case %d: %d\n",cs,call(n));
    }
}
