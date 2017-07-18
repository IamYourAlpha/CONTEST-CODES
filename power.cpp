
#include<stdio.h>

int main() {
    int input,pow=1,i;
    int flag = 0;
    scanf("%d",&input);
    for(i=0;; i++) {
        if(input==pow) {
            flag = 1;
            break;
        } else if(input<pow) {
            flag = 0;
            break;
        } else pow = pow * 2;
    }
    if(flag==1) printf("It's a power of 2\n");
    else printf("It's not a power of 2\n");
    return 0;
}
