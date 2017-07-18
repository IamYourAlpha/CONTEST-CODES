using namespace std;
# include <iostream>
#include<stdio.h>

int main() {
      while(true) {
            string str="";
            char ch;
            int c;
      for(int i=0;;i++){
            if(scanf("%c",&ch)==EOF) return 0;
            else if(ch=='#') break;
            else str+=ch;
      }
     // cout<<str<<endl;
            c=0;
            for(int i=str.length()-1;i>=0;i--){
                    c*=2;
                    c+= str[i]-'0';
                    c%=131071;
            }
            if(!c) printf("YES\n");
            else printf("NO\n");
      }
      return 0;
}
