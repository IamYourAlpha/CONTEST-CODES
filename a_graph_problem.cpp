#include<stdio.h>

int memo[100];
int n;
int main() {
    memo[2] = memo[3] =  2;
    memo[1] = 1;
    for(int i=4 ; i<79 ; i++) memo[i] = memo[i-2] +  memo[i-3];
    while(scanf("%d",&n)==1)
        printf("%d\n",memo[n]);
    return 0;
}
