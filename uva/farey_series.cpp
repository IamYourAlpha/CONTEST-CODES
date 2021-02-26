#include<bits/stdc++.h>
using namespace std;

int main() {
//freopen("in.txt","r",stdin);
    int n,kk;
    int a,b,c,d;
    int p,q;
    while(scanf("%d %d",&n,&kk)!=EOF) {
        a = 0;
        b = 1;
        c = 1;
        d = n;
        int k;
        for(int i=1; i<kk; i++) {
            k = (n+b)/d;
            p = k*c - a;
            q = k*d - b;
            a = c;
            b = d;
            c = p;
            d = q;
          //  cout << c << "/" << d << endl;
        }
        cout << c <<"/" << d <<endl;
    }
    return 0;
}
