#include<stdio.h>

int main(){
    int a,b;
    printf("enter the value of a and b\n");
    scanf("%d %d",&a,&b);
      if(b==0) a = 1;
     for(int i=1;i<b;i++){
      a = a*a;
      }
      printf("%d\n",a);
      return 0;
      }

