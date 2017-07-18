using namespace std;
#include<bits/stdc++.h>
typedef long long ll;

int main() {
    ll Catalan[50];
    ll  SuperCatalan[50];
    memset(SuperCatalan,0,sizeof(SuperCatalan));
    memset(Catalan,0,sizeof(Catalan));
    Catalan[0]= 1;
    Catalan[1] = 1;

    for(int i=2; i<35; i++)
        for(int j=0; j<i; j++)
            Catalan[i] = Catalan[i] + Catalan[j] * Catalan[i-j-1];

    // for(int i=0; i<50; i++) cout << f[i] << endl;
    SuperCatalan[0] = SuperCatalan[1] = SuperCatalan[2] = 1;
    for(int i=3; i<35; i++) SuperCatalan[i]  = (  ( 3*(2*i-3) * SuperCatalan[i-1] ) - ( (i-3) * SuperCatalan[i-2] ) )/i;
    int n;
    while(~scanf("%d",&n))
        cout << SuperCatalan[n] - Catalan[n-1] << endl;
    return 0;
}

