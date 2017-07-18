#include<stdio.h>
#include<string.h>
int main() {

    char str [10000];
    scanf("%s",str);
    char *token =  strtok(str," ");
    while(token != NULL) {
        printf("%s\n",token);
        token = strtok(NULL," ");
    }
    return 0;
}
