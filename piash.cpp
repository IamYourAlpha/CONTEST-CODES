#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main() {
    char str[1010] = "1-2-3-4-5-10";
    char ch[2] = "-";
    char *mypoint;
    mypoint = strtok(str,ch);
    while(mypoint!=NULL) {
        int out = atoi(mypoint);
        printf("%d ",out);
        mypoint = strtok(NULL,ch);
    }
    return 0;
}
