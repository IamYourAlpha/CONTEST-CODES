#include<stdio.h>

int main(){
    int n;
    int sum = 0;
     int c = 0;
      for(int i = 7; ; i += 13) {  c++; if(c==100) break; sum += i;}
      printf("%d\n",sum);
      return 0;
}
