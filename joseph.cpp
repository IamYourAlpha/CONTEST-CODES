#include<bits/stdc++.h>
using namespace std;

int memo [10000];
int m,k;

int round(int k ,int m) {
    int sz = 2 * k;
    int i =0;
    int now = (m-1) % sz;
    for( i = 0; i<2*k ; i++) {
        if(now < k ) break;
        sz--;
        now = (now + m-1) % sz;
    }
    return i;
}

void solve() {
    for(int i= 1; i<=14; i++) {
        for(int j = 1;; j++) {
            if(round(i,j) == i) {
                memo [i] = j;
                break;
            }
        }
    }
}

int main() {
    solve();
    while(scanf("%d",&k) != EOF && k) {
        cout << memo [k] <<  endl;
    }
    return 0;
}
