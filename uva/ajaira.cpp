#include<stdio.h>

int check(int tot) {
    return ( (tot%5!=0)||(tot<5) ) ? -1:tot/5;
}
int main() {
    int in;
    int tot=0;
    for(int i=0; i<5; i++) {scanf("%d",&in);tot+=in;}
    printf("%d",check(tot));
    return 0;
}

