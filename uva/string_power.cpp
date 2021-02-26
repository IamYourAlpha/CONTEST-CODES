#include<bits/stdc++.h>
using namespace std;
#define safe 100000

int main() {
    char input[1000005];
    int power;
    bool check;
    while(scanf("%s",input)==1) {
        check = true;
        if(strcmp(input,".")==0)  break;
        int len = strlen(input);
        for(int i=1; i<=len; i++) {
            if(len%i==0) {
                power = len/i;
                check = true;
                for(int k = 0; k<i; k++) {
                    for(int m = k+i; m<len; m+=i) {
                        if(input[k]!=input[m]) {
                            check = false;
                            break;
                        }
                    }
                }
                if(check) break;
            }
        }
        cout << power << endl;
    }
    return 0;
}

