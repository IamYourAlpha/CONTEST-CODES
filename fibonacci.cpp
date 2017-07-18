#include<bits/stdc++.h>
using namespace std;

int main() {
    int fibo[1000];
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;

    for(int i=3; i<100; i++) fibo [i] = fibo [i-1] + fibo [i-2];
    for(int i=0; i<10; i++) cout << fibo[i] << endl;
    return 0;
}
